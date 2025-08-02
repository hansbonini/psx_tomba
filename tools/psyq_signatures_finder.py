#!/usr/bin/python3

# signatures:
# https://github.com/lab313ru/psx_psyq_signatures

import json


def match_signature(data, sig: str):
    if len(sig) == 0:
        return 0

    tokens = []
    for ch in sig.split(" "):
        if ch == " " or len(ch) == 0:
            continue
        if ch == "??":
            tokens.append(None)
        else:
            tokens.append(int(ch, 16))

    n_tokens = len(tokens)
    i = 0
    while i + n_tokens < len(data):
        start = i
        found = True
        for t in tokens:
            ch = data[i]
            i += 1
            if t == None:
                continue
            if t != ch:
                found = False
                break
        if found:
            return start
    return -1


def parse_libsig(lib_name, path, data):
    res = []
    with open(path, "r") as f:
        lib = json.load(f)

    for obj in lib:
        if "sig" not in obj:
            continue
        sig = obj["sig"]
        offset = match_signature(data, sig)
        if offset < 0:
            continue
        obj_name = str(obj["name"]).lower().replace(".obj", "")
        r = dict()
        r["lib"] = lib_name
        r["obj"] = obj_name
        r["data"] = obj
        r["off"] = offset
        res.append(r)
    return res


with open("./iso/us/SCUS_942.36", "rb") as f:
    data = f.read()

res = []
for lib_name in [
    "libapi",
    "libc2",
    "libcard",
    "libcd",
    "libc",
    "libcomb",
    "libetc",
    "libgpu",
    "libgs",
    "libgte",
    "libgun",
    "libmath",
    "libpress",
    "libsnd",
    "libsn",
    "libspu",
    "libtap",
]:
    sig_path = f"./tools/psx_psyq_signatures/350/{lib_name.upper()}.LIB.json"
    res.extend(parse_libsig(lib_name, sig_path, data))
for obj_name in ["2mbyte", "8mbyte", "none2", "none3"]:
    sig_path = f"./tools/psx_psyq_signatures/350/{obj_name.upper()}.OBJ.json"
    res.extend(parse_libsig(obj_name, sig_path, data))

# print splat subsegment
for r in sorted(res, key=lambda item: item["off"]):
    lib_name = r["lib"]
    obj_name = r["obj"]
    obj = r["data"]
    offset = r["off"]
    print(f"- [0x{offset:X}, c, psxsdk/{lib_name}, {obj_name}]")

# print symbol list
vram = 0x80010000
for r in res:
    offset = r["off"]
    obj = r["data"]
    if "labels" not in obj:
        continue
    labels = obj["labels"]
    for label in labels:
        name = str(label["name"])
        if name.startswith("loc_"):
            continue
        if name.startswith("text_"):
            continue
        final_off = vram + offset + label["offset"] - 0x800
        print(f"{name} = 0x{final_off:X};")