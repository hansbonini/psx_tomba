#include "common.h"
#include "game.h"


u8 D_80077428[0xC8] = {
    [EVENT_GRANDPASBRACELET]                           = 0x02,
    [EVENT_THE100YEAROLDWISEMAN]                       = 0x03,
    [EVENT_CLEARTHEFOG]                                = 0x04,
    [EVENT_TAKEMEHOME]                                 = 0x06,
    [EVENT_MOTOCROSSCOURSE]                            = 0x08,
    [EVENT_WHOAREYOU]                                  = 0x09,
    [EVENT_ALARGEPUDDLE]                               = 0xFF,
    [EVENT_HIDEANDGOSEEK]                              = 0x0A,
    [EVENT_ICANTSWIM]                                  = 0x0B,
    [EVENT_INSIDETHEKOKKAEGGS]                         = 0x0C,
    [EVENT_TALEOFTHEEVILPIGS]                          = 0x0D,
    [EVENT_THE1000YEAROLDMAN]                          = 0x48,
    [EVENT_DWARFELDER]                                 = 0x0E,
    [EVENT_BEGINNERSDWARFLANGUAGE]                     = 0x0F,
    [EVENT_ALOSTCHILD]                                 = 0x13,
    [EVENT_FLOWERSEEDS]                                = 0x14,
    [EVENT_THEAPBOX]                                   = 0x15,
    [EVENT_SAVETHEDWARVES]                             = 0x16,
    [EVENT_TEACHINGOFTHEDWARVES]                       = 0xFF,
    [EVENT_LOSTANDFOUND]                               = 0x1C,
    [EVENT_STOPTHEFIGHT]                               = 0x1E,
    [EVENT_THEGREATESCAPE]                             = 0x1F,
    [EVENT_LOOKANDSEE]                                 = 0x20,
    [EVENT_AMANSBESTFRIEND]                            = 0x22,
    [EVENT_WHATISTHIS]                                 = 0x27,
    [EVENT_TREASURESFROMTHEMANSION]                    = 0x28,
    [EVENT_TOPHOENIXMOUNTAIN]                          = 0x1A,
    [EVENT_THEBROKENFOUNTAIN]                          = 0x2F,
    [EVENT_AFAMILIARLOOKINGMANSION]                    = 0x30,
    [EVENT_ASTORMYPIGBAG]                              = 0x31,
    [EVENT_PHOENIXMOUNTAIN]                            = 0x32,
    [EVENT_WHEREDIDICOMEFROM]                          = 0x33,
    [EVENT_MINIATUREMAKINGTRUMPETS]                    = 0x34,
    [EVENT_THEFAMOUSDIGGER]                            = 0x35,
    [EVENT_LAVACAVES]                                  = 0x37,
    [EVENT_THEMASTEOFSKIES]                            = 0x38,
    [EVENT_WHATSAFUNGA]                                = 0x39,
    [EVENT_MONSTERHUNT]                                = 0x3D,
    [EVENT_DEATHFRUITJUICE]                            = 0x3E,
    [EVENT_PLANTAFLOWERGARDEN]                         = 0x40,
    [EVENT_TEARSFROMAFLOWER]                           = 0x41,
    [EVENT_SMILE]                                      = 0x42,
    [EVENT_CRYBABY]                                    = 0x43,
    [EVENT_CANTSTOPCRYING]                             = 0x44,
    [EVENT_THEREDFORTUNETELLER]                        = 0x45,
    [EVENT_APSLOTMACHINE]                              = 0xFF,
    [EVENT_WHERESTHEBABYMOUSE]                         = 0x46,
    [EVENT_SOMECHEESEPLEASE]                           = 0x47,
    [EVENT_APOINTSHOW]                                 = 0xFF,
    [EVENT_ADRINKFORGOWNUPS]                           = 0x49,
    [EVENT_ROADTOBACCUSLAKE]                           = 0x4A,
    [EVENT_ASMALLKEYHOLE]                              = 0x4B,
    [EVENT_ABABYSBRIDGE]                               = 0xFF,
    [EVENT_THEMOUSEPIGBAG]                             = 0x4C,
    [EVENT_THEHAUNTEDMANSION]                          = 0x4F,
    [EVENT_ALARGEKEYHOLE]                              = 0x50,
    [EVENT_PAINTINGOFABIGKEY]                          = 0x51,
    [EVENT_BREAKTHEMAGICEGG]                           = 0x52,
    [EVENT_REDHIDDENPOWERS]                            = 0x53,
    [EVENT_THEELDERREQUEST]                            = 0xFF,
    [EVENT_LETSLEARNWORDS2]                            = 0xFF,
    [EVENT_JUNGLEOFTHEMASAKARITRIBE]                   = 0xFF,
    [EVENT_TREEOFKNOWLEDGEKNOWS]                       = 0x59,
    [EVENT_THEPUMPROCKS]                               = 0x56,
    [EVENT_AREFRESHINGDRINK]                           = 0x58,
    [EVENT_INEEDATEARBOTTLE]                           = 0x5B,
    [EVENT_THESTOLENPICTUREBOOKOFTHEISLAND]            = 0xFF,
    [EVENT_DECIPHERSCRIBBLEINSLAND]                    = 0xFF,
    [EVENT_SECRETOFTHEISLAND1]                         = 0xFF,
    [EVENT_SECRETOFTHEISLAND2]                         = 0xFF,
    [EVENT_SECRETOFTHEISLAND3]                         = 0xFF,
    [EVENT_SECRETOFTHEISLAND4]                         = 0xFF,
    [EVENT_SECRETOFTHEISLAND5]                         = 0xFF,
    [EVENT_WENEEDPOWER]                                = 0x5C,
    [EVENT_CATCHTHEELECTRICITY]                        = 0xFF,
    [EVENT_ANINCIDENTFINDTHECULPRIT]                   = 0xFF,
    [EVENT_WONDERSOFTHEBLACKWATER]                     = 0xFF,
    [EVENT_THECIVILIZATIONMACHINE]                     = 0x5F,
    [EVENT_FINDCHARLES]                                = 0x57,
    [EVENT_WHATSUNDERTHEFOREST]                        = 0x62,
    [EVENT_THE100FLOWERFOREST]                         = 0x19,
    [EVENT_THEBOSSTREASURE]                            = 0x71,
    [EVENT_IMSOHUNGRY]                                 = 0x81,
    [EVENT_THERUSTYSTEELCAR]                           = 0xFF,
    [EVENT_UNKNOWN21]                                  = 0xFF,
    [EVENT_THEDEEPJUNGLEPIG]                           = 0x55,
    [EVENT_HEALINGHERBSFORBARON]                       = 0x23,
    [EVENT_DELICIOUSKNOWLEDGEFRUIT]                    = 0x24,
    [EVENT_SEAWEEDFORYOURHEALTH]                       = 0x26,
    [EVENT_UNKNOWN22]                                  = 0xFF,
    [EVENT_BLUEHIDDENPOWERS]                           = 0x6C,
    [EVENT_THEPIGSVILLAGE]                             = 0xFF,
    [EVENT_THEHOUSEWITHWHITESMOKE]                     = 0xFF,
    [EVENT_LETSLEARNWORDS3]                            = 0xFF,
    [EVENT_LETSGETALONG]                               = 0xFF,
    [EVENT_ABROKENBRIDGE]                              = 0xFF,
    [EVENT_THEGREATBOULDERINTHEVILLAGEOFTHETREEPEOPLE] = 0xFF,
    [EVENT_WHATTIMEISIT]                               = 0xFF,
    [EVENT_UNKNOWN30]                                  = 0xFF,
    [EVENT_THEUNBREAKABLEGEAR]                         = 0xFF,
    [EVENT_ABIGKEYHOLE]                                = 0xFF,
    [EVENT_HOWAREWEGOINDTOKAEIT]                       = 0xFF,
    [EVENT_BREAKTHERUSTYDOOR]                          = 0x5D,
    [EVENT_THECUTEWITCH]                               = 0x64,
    [EVENT_FOODFORFUEL]                                = 0x63,
    [EVENT_INEEDABOMB]                                 = 0x5E,
    [EVENT_UNKNOWN34]                                  = 0xFF,
    [EVENT_UNKNOWN35]                                  = 0xFF,
    [EVENT_UNKNOWN36]                                  = 0xFF,
    [EVENT_THEPIGGLASSESINTHEPIGVILLAGE]               = 0xFF,
    [EVENT_UNKNOWN38]                                  = 0xFF,
    [EVENT_BACCUSVILLAGE]                              = 0x4D,
    [EVENT_THEMERMAIDNECKLACE]                         = 0x69,
    [EVENT_BARONSSTRENGTH]                             = 0x25,
    [EVENT_WHATTHEWITCHLOST]                           = 0x73,
    [EVENT_ASAFEMUSHROOM]                              = 0x2C,
    [EVENT_POWERUPFORTOOLS]                            = 0x68,
    [EVENT_UNKNOWN39]                                  = 0xFF,
    [EVENT_THE10000YEAROLDMAN]                         = 0x60,
    [EVENT_MIGHTYFISHFOOD]                             = 0x6B,
    [EVENT_LETSMAKECANDY]                              = 0x72,
    [EVENT_THEMERMAIDSINGINGROCK]                      = 0x75,
    [EVENT_THEPIRATESTREASURE]                         = 0xFF,
    [EVENT_THEUNDERWATERPIG]                           = 0x65,
    [EVENT_TRICKVILLAGE]                               = 0x66,
    [EVENT_THETHIEFSDOOR]                              = 0x79,
    [EVENT_THE10MATHBEADS]                             = 0x67,
    [EVENT_THE5GOLDENITEMS]                            = 0x6E,
    [EVENT_UNBREAKABLEWIRE]                            = 0x7B,
    [EVENT_GREENHIDDENPOWERS]                          = 0x80,
    [EVENT_UNKNOWN41]                                  = 0xFF,
    [EVENT_UNKNOWN42]                                  = 0xFF,
    [EVENT_TAKETWOOFTHESE]                             = 0x74,
    [EVENT_IWANTABRONZEMEDAL]                          = 0x76,
    [EVENT_IWANTASILVERMEDAL]                          = 0x77,
    [EVENT_IWANTAGOLDMEDAL]                            = 0x78,
    [EVENT_UNKNOWN43]                                  = 0xFF,
    [EVENT_UNKNOWN44]                                  = 0xFF,
    [EVENT_UNKNOWN45]                                  = 0xFF,
    [EVENT_UNKNOWN46]                                  = 0xFF,
    [EVENT_THETHREESISTERSOFKARAKURIFORT]              = 0xFF,
    [EVENT_LETTERSOFTHETHREESISTERS]                   = 0xFF,
    [EVENT_UNKNOWN49]                                  = 0xFF,
    [EVENT_UNKNOWN50]                                  = 0xFF,
    [EVENT_MILLIONYEAROLDWISH]                         = 0x7C,
    [EVENT_DIGLIKEAMOLE]                               = 0x7A,
    [EVENT_THEBLUEFORTUNETELLER]                       = 0x7D,
    [EVENT_UNKNOWN51]                                  = 0xFF,
    [EVENT_UNKNOWN52]                                  = 0xFF,
    [EVENT_UNKNOWN53]                                  = 0xFF,
    [EVENT_LETSRIDETHERAFT]                            = 0x61,
    [EVENT_TAKEOUT]                                    = 0x82,
    [EVENT_UNKNOWN54]                                  = 0xFF,
    [EVENT_WHATSTHEUNDERWATER]                         = 0x6A,
    [EVENT_UNKNOWN55]                                  = 0xFF,
    [EVENT_UNKNOWN56]                                  = 0xFF,
    [EVENT_SOURCEOFEVILMAGIC]                          = 0x6D,
    [EVENT_SEVENFRIENDS]                               = 0x84,
    [EVENT_UNKNOWN57]                                  = 0xFF,
    [EVENT_THE8THEVILPIGBAG]                           = 0x83,
    [EVENT_THEREALEVILPIG]                             = 0x85,
    [EVENT_UNDERGROUNDTREASURE]                        = 0x7F,
    [EVENT_UNKNOWN58]                                  = 0xFF,
    [EVENT_UNKNOWN59]                                  = 0xFF,
    [EVENT_THEFLOWERTOWER]                             = 0x86,
    [EVENT_UNKNOWN60]                                  = 0xFF,
    [EVENT_AHUNGRYMONKEY]                              = 0x05,
    [EVENT_PEACHFLOWERGAS]                             = 0x07,
    [EVENT_THEEVILPIGBAG]                              = 0x18,
    [EVENT_BITINGPLANTFLOWER]                          = 0x1B,
    [EVENT_WHENTHEWINDDIESDOWN]                        = 0x3A,
    [EVENT_THEPHOENIXFAVORITE]                         = 0x3F,
    [EVENT_THEFIREPIGBAG]                              = 0x36,
    [EVENT_CHARLESPANTS]                               = 0x3B,
    [EVENT_THEHAUNTEDPIGBAG]                           = 0x4E,
    [EVENT_THEWORLDSGREATESTSMILE]                     = 0x2D,
    [EVENT_THEWORLDSGREATESTPOUT]                      = 0x2E,
    [EVENT_SOMETHINGCOOKIN]                            = 0x10,
    [EVENT_LEAFBUTTERFLIES]                            = 0x11,
    [EVENT_WHEREDTHELIGHTSGO]                          = 0x12,
    [EVENT_WHERETHEBARRELSROLLS]                       = 0x17,
    [EVENT_READYSETGO]                                 = 0x21,
    [EVENT_AMAGICMIRROR]                               = 0x1D,
    [EVENT_THEJUNGLEPIGBAG]                            = 0x54,
    [EVENT_UNKNOWN61]                                  = 0xFF,
    [EVENT_APRECIOUSTREASURECHEST]                     = 0x3C,
    [EVENT_UNKNOWN62]                                  = 0xFF,
    [EVENT_THEMISTERIOUSMUSHROOM]                      = 0x29,
    [EVENT_LEAFSLIDER]                                 = 0x2A,
    [EVENT_REDBLUE]                                    = 0x2B,
    [EVENT_THETROUBLEDTHIEF]                           = 0x6F,
    [EVENT_WHATTHETHIEFFORGOT]                         = 0x70,
    [EVENT_UNKNOWN63]                                  = 0xFF,
    [EVENT_UNKNOWN64]                                  = 0xFF,
    [EVENT_UNKNOWN65]                                  = 0xFF,
    [EVENT_UNKNOWN66]                                  = 0xFF,
    [EVENT_UNKNOWN67]                                  = 0xFF,
    [EVENT_UNKNOWN68]                                  = 0xFF,
    [EVENT_UNKNOWN69]                                  = 0xFF,
    [EVENT_UNKNOWN70]                                  = 0xFF,
};

s16 D_800774F0[4] = { 0, 0xB4, 0, 0 };

u16 D_800774F8[8] = { 0, 1, 2, 3, 4, 5, 6, 0 };

unk_80077720 D_80077508[6] = {
    { 0xFFD8, 0 },
    { 0xFFEC, 0 },
    { 0, 0 },
    { 20, 0 },
    { 40, 0 },
    { 60, 0 }
};

int AP_TABLE[8] = { 0, 500, 1000, 2000, 5000, 10000, 20000, 50000 };

u_char EVENT_STARTED_AP_TABLE[0xC8] = {
    [EVENT_GRANDPASBRACELET]                           = 0,
    [EVENT_THE100YEAROLDWISEMAN]                       = 0,
    [EVENT_CLEARTHEFOG]                                = 1,
    [EVENT_TAKEMEHOME]                                 = 2,
    [EVENT_MOTOCROSSCOURSE]                            = 0,
    [EVENT_WHOAREYOU]                                  = 2,
    [EVENT_ALARGEPUDDLE]                               = 0,
    [EVENT_HIDEANDGOSEEK]                              = 2,
    [EVENT_ICANTSWIM]                                  = 1,
    [EVENT_INSIDETHEKOKKAEGGS]                         = 1,
    [EVENT_TALEOFTHEEVILPIGS]                          = 0,
    [EVENT_THE1000YEAROLDMAN]                          = 1,
    [EVENT_DWARFELDER]                                 = 0,
    [EVENT_BEGINNERSDWARFLANGUAGE]                     = 0,
    [EVENT_ALOSTCHILD]                                 = 1,
    [EVENT_FLOWERSEEDS]                                = 4,
    [EVENT_THEAPBOX]                                   = 2,
    [EVENT_SAVETHEDWARVES]                             = 1,
    [EVENT_TEACHINGOFTHEDWARVES]                       = 0,
    [EVENT_LOSTANDFOUND]                               = 2,
    [EVENT_STOPTHEFIGHT]                               = 3,
    [EVENT_THEGREATESCAPE]                             = 3,
    [EVENT_LOOKANDSEE]                                 = 2,
    [EVENT_AMANSBESTFRIEND]                            = 3,
    [EVENT_WHATISTHIS]                                 = 3,
    [EVENT_TREASURESFROMTHEMANSION]                    = 2,
    [EVENT_TOPHOENIXMOUNTAIN]                          = 0,
    [EVENT_THEBROKENFOUNTAIN]                          = 2,
    [EVENT_AFAMILIARLOOKINGMANSION]                    = 2,
    [EVENT_ASTORMYPIGBAG]                              = 0,
    [EVENT_PHOENIXMOUNTAIN]                            = 0,
    [EVENT_WHEREDIDICOMEFROM]                          = 2,
    [EVENT_MINIATUREMAKINGTRUMPETS]                    = 2,
    [EVENT_THEFAMOUSDIGGER]                            = 2,
    [EVENT_LAVACAVES]                                  = 0,
    [EVENT_THEMASTEOFSKIES]                            = 1,
    [EVENT_WHATSAFUNGA]                                = 2,
    [EVENT_MONSTERHUNT]                                = 2,
    [EVENT_DEATHFRUITJUICE]                            = 2,
    [EVENT_PLANTAFLOWERGARDEN]                         = 2,
    [EVENT_TEARSFROMAFLOWER]                           = 2,
    [EVENT_SMILE]                                      = 2,
    [EVENT_CRYBABY]                                    = 2,
    [EVENT_CANTSTOPCRYING]                             = 2,
    [EVENT_THEREDFORTUNETELLER]                        = 2,
    [EVENT_APSLOTMACHINE]                              = 0,
    [EVENT_WHERESTHEBABYMOUSE]                         = 1,
    [EVENT_SOMECHEESEPLEASE]                           = 2,
    [EVENT_APOINTSHOW]                                 = 0,
    [EVENT_ADRINKFORGOWNUPS]                           = 1,
    [EVENT_ROADTOBACCUSLAKE]                           = 1,
    [EVENT_ASMALLKEYHOLE]                              = 1,
    [EVENT_ABABYSBRIDGE]                               = 0,
    [EVENT_THEMOUSEPIGBAG]                             = 0,
    [EVENT_THEHAUNTEDMANSION]                          = 0,
    [EVENT_ALARGEKEYHOLE]                              = 1,
    [EVENT_PAINTINGOFABIGKEY]                          = 1,
    [EVENT_BREAKTHEMAGICEGG]                           = 1,
    [EVENT_REDHIDDENPOWERS]                            = 2,
    [EVENT_THEELDERREQUEST]                            = 0,
    [EVENT_LETSLEARNWORDS2]                            = 0,
    [EVENT_JUNGLEOFTHEMASAKARITRIBE]                   = 0,
    [EVENT_TREEOFKNOWLEDGEKNOWS]                       = 2,
    [EVENT_THEPUMPROCKS]                               = 2,
    [EVENT_AREFRESHINGDRINK]                           = 1,
    [EVENT_INEEDATEARBOTTLE]                           = 2,
    [EVENT_THESTOLENPICTUREBOOKOFTHEISLAND]            = 0,
    [EVENT_DECIPHERSCRIBBLEINSLAND]                    = 0,
    [EVENT_SECRETOFTHEISLAND1]                         = 0,
    [EVENT_SECRETOFTHEISLAND2]                         = 0,
    [EVENT_SECRETOFTHEISLAND3]                         = 0,
    [EVENT_SECRETOFTHEISLAND4]                         = 0,
    [EVENT_SECRETOFTHEISLAND5]                         = 0,
    [EVENT_WENEEDPOWER]                                = 1,
    [EVENT_CATCHTHEELECTRICITY]                        = 0,
    [EVENT_ANINCIDENTFINDTHECULPRIT]                   = 0,
    [EVENT_WONDERSOFTHEBLACKWATER]                     = 1,
    [EVENT_THECIVILIZATIONMACHINE]                     = 0,
    [EVENT_FINDCHARLES]                                = 1,
    [EVENT_WHATSUNDERTHEFOREST]                        = 1,
    [EVENT_THE100FLOWERFOREST]                         = 0,
    [EVENT_THEBOSSTREASURE]                            = 2,
    [EVENT_IMSOHUNGRY]                                 = 3,
    [EVENT_THERUSTYSTEELCAR]                           = 2,
    [EVENT_UNKNOWN21]                                  = 0,
    [EVENT_THEDEEPJUNGLEPIG]                           = 0,
    [EVENT_HEALINGHERBSFORBARON]                       = 2,
    [EVENT_DELICIOUSKNOWLEDGEFRUIT]                    = 2,
    [EVENT_SEAWEEDFORYOURHEALTH]                       = 2,
    [EVENT_UNKNOWN22]                                  = 0,
    [EVENT_BLUEHIDDENPOWERS]                           = 0,
    [EVENT_THEPIGSVILLAGE]                             = 2,
    [EVENT_THEHOUSEWITHWHITESMOKE]                     = 0,
    [EVENT_LETSLEARNWORDS3]                            = 0,
    [EVENT_LETSGETALONG]                               = 0,
    [EVENT_ABROKENBRIDGE]                              = 0,
    [EVENT_THEGREATBOULDERINTHEVILLAGEOFTHETREEPEOPLE] = 0,
    [EVENT_WHATTIMEISIT]                               = 0,
    [EVENT_UNKNOWN30]                                  = 0,
    [EVENT_THEUNBREAKABLEGEAR]                         = 0,
    [EVENT_ABIGKEYHOLE]                                = 0,
    [EVENT_HOWAREWEGOINDTOKAEIT]                       = 0,
    [EVENT_BREAKTHERUSTYDOOR]                          = 1,
    [EVENT_THECUTEWITCH]                               = 2,
    [EVENT_FOODFORFUEL]                                = 2,
    [EVENT_INEEDABOMB]                                 = 1,
    [EVENT_UNKNOWN34]                                  = 0,
    [EVENT_UNKNOWN35]                                  = 0,
    [EVENT_UNKNOWN36]                                  = 0,
    [EVENT_THEPIGGLASSESINTHEPIGVILLAGE]               = 0,
    [EVENT_UNKNOWN38]                                  = 0,
    [EVENT_BACCUSVILLAGE]                              = 0,
    [EVENT_THEMERMAIDNECKLACE]                         = 2,
    [EVENT_BARONSSTRENGTH]                             = 2,
    [EVENT_WHATTHEWITCHLOST]                           = 2,
    [EVENT_ASAFEMUSHROOM]                              = 2,
    [EVENT_POWERUPFORTOOLS]                            = 2,
    [EVENT_UNKNOWN39]                                  = 0,
    [EVENT_THE10000YEAROLDMAN]                         = 1,
    [EVENT_MIGHTYFISHFOOD]                             = 2,
    [EVENT_LETSMAKECANDY]                              = 2,
    [EVENT_THEMERMAIDSINGINGROCK]                      = 2,
    [EVENT_THEPIRATESTREASURE]                         = 0,
    [EVENT_THEUNDERWATERPIG]                           = 0,
    [EVENT_TRICKVILLAGE]                               = 0,
    [EVENT_THETHIEFSDOOR]                              = 1,
    [EVENT_THE10MATHBEADS]                             = 1,
    [EVENT_THE5GOLDENITEMS]                            = 2,
    [EVENT_UNBREAKABLEWIRE]                            = 1,
    [EVENT_GREENHIDDENPOWERS]                          = 2,
    [EVENT_UNKNOWN41]                                  = 0,
    [EVENT_UNKNOWN42]                                  = 0,
    [EVENT_TAKETWOOFTHESE]                             = 2,
    [EVENT_IWANTABRONZEMEDAL]                          = 2,
    [EVENT_IWANTASILVERMEDAL]                          = 2,
    [EVENT_IWANTAGOLDMEDAL]                            = 2,
    [EVENT_UNKNOWN43]                                  = 0,
    [EVENT_UNKNOWN44]                                  = 0,
    [EVENT_UNKNOWN45]                                  = 0,
    [EVENT_UNKNOWN46]                                  = 0,
    [EVENT_THETHREESISTERSOFKARAKURIFORT]              = 0,
    [EVENT_LETTERSOFTHETHREESISTERS]                   = 0,
    [EVENT_UNKNOWN49]                                  = 0,
    [EVENT_UNKNOWN50]                                  = 0,
    [EVENT_MILLIONYEAROLDWISH]                         = 1,
    [EVENT_DIGLIKEAMOLE]                               = 1,
    [EVENT_THEBLUEFORTUNETELLER]                       = 2,
    [EVENT_UNKNOWN51]                                  = 0,
    [EVENT_UNKNOWN52]                                  = 0,
    [EVENT_UNKNOWN53]                                  = 0,
    [EVENT_LETSRIDETHERAFT]                            = 2,
    [EVENT_TAKEOUT]                                    = 2,
    [EVENT_UNKNOWN54]                                  = 0,
    [EVENT_WHATSTHEUNDERWATER]                         = 1,
    [EVENT_UNKNOWN55]                                  = 0,
    [EVENT_UNKNOWN56]                                  = 0,
    [EVENT_SOURCEOFEVILMAGIC]                          = 0,
    [EVENT_SEVENFRIENDS]                               = 1,
    [EVENT_UNKNOWN57]                                  = 0,
    [EVENT_THE8THEVILPIGBAG]                           = 0,
    [EVENT_THEREALEVILPIG]                             = 0,
    [EVENT_UNDERGROUNDTREASURE]                        = 2,
    [EVENT_UNKNOWN58]                                  = 0,
    [EVENT_UNKNOWN59]                                  = 0,
    [EVENT_THEFLOWERTOWER]                             = 2,
    [EVENT_UNKNOWN60]                                  = 0,
    [EVENT_AHUNGRYMONKEY]                              = 2,
    [EVENT_PEACHFLOWERGAS]                             = 3,
    [EVENT_THEEVILPIGBAG]                              = 0,
    [EVENT_BITINGPLANTFLOWER]                          = 5,
    [EVENT_WHENTHEWINDDIESDOWN]                        = 2,
    [EVENT_THEPHOENIXFAVORITE]                         = 2,
    [EVENT_THEFIREPIGBAG]                              = 0,
    [EVENT_CHARLESPANTS]                               = 2,
    [EVENT_THEHAUNTEDPIGBAG]                           = 0,
    [EVENT_THEWORLDSGREATESTSMILE]                     = 1,
    [EVENT_THEWORLDSGREATESTPOUT]                      = 1,
    [EVENT_SOMETHINGCOOKIN]                            = 3,
    [EVENT_LEAFBUTTERFLIES]                            = 2,
    [EVENT_WHEREDTHELIGHTSGO]                          = 2,
    [EVENT_WHERETHEBARRELSROLLS]                       = 1,
    [EVENT_READYSETGO]                                 = 2,
    [EVENT_AMAGICMIRROR]                               = 2,
    [EVENT_THEJUNGLEPIGBAG]                            = 1,
    [EVENT_UNKNOWN61]                                  = 0,
    [EVENT_APRECIOUSTREASURECHEST]                     = 1,
    [EVENT_UNKNOWN62]                                  = 0,
    [EVENT_THEMISTERIOUSMUSHROOM]                      = 2,
    [EVENT_LEAFSLIDER]                                 = 2,
    [EVENT_REDBLUE]                                    = 2,
    [EVENT_THETROUBLEDTHIEF]                           = 2,
    [EVENT_WHATTHETHIEFFORGOT]                         = 2,
    [EVENT_UNKNOWN63]                                  = 0,
    [EVENT_UNKNOWN64]                                  = 0,
    [EVENT_UNKNOWN65]                                  = 0,
    [EVENT_UNKNOWN66]                                  = 0,
    [EVENT_UNKNOWN67]                                  = 0,
    [EVENT_UNKNOWN68]                                  = 0,
    [EVENT_UNKNOWN69]                                  = 0,
    [EVENT_UNKNOWN70]                                  = 0,
};

u_char EVENT_COMPLETE_AP_TABLE[0xC8] = {
    [EVENT_GRANDPASBRACELET]                           = 0,
    [EVENT_THE100YEAROLDWISEMAN]                       = 2,
    [EVENT_CLEARTHEFOG]                                = 2,
    [EVENT_TAKEMEHOME]                                 = 3,
    [EVENT_MOTOCROSSCOURSE]                            = 1,
    [EVENT_WHOAREYOU]                                  = 4,
    [EVENT_ALARGEPUDDLE]                               = 0,
    [EVENT_HIDEANDGOSEEK]                              = 5,
    [EVENT_ICANTSWIM]                                  = 2,
    [EVENT_INSIDETHEKOKKAEGGS]                         = 2,
    [EVENT_TALEOFTHEEVILPIGS]                          = 1,
    [EVENT_THE1000YEAROLDMAN]                          = 2,
    [EVENT_DWARFELDER]                                 = 3,
    [EVENT_BEGINNERSDWARFLANGUAGE]                     = 3,
    [EVENT_ALOSTCHILD]                                 = 3,
    [EVENT_FLOWERSEEDS]                                = 3,
    [EVENT_THEAPBOX]                                   = 2,
    [EVENT_SAVETHEDWARVES]                             = 4,
    [EVENT_TEACHINGOFTHEDWARVES]                       = 0,
    [EVENT_LOSTANDFOUND]                               = 3,
    [EVENT_STOPTHEFIGHT]                               = 4,
    [EVENT_THEGREATESCAPE]                             = 3,
    [EVENT_LOOKANDSEE]                                 = 2,
    [EVENT_AMANSBESTFRIEND]                            = 4,
    [EVENT_WHATISTHIS]                                 = 4,
    [EVENT_TREASURESFROMTHEMANSION]                    = 3,
    [EVENT_TOPHOENIXMOUNTAIN]                          = 2,
    [EVENT_THEBROKENFOUNTAIN]                          = 4,
    [EVENT_AFAMILIARLOOKINGMANSION]                    = 1,
    [EVENT_ASTORMYPIGBAG]                              = 2,
    [EVENT_PHOENIXMOUNTAIN]                            = 6,
    [EVENT_WHEREDIDICOMEFROM]                          = 3,
    [EVENT_MINIATUREMAKINGTRUMPETS]                    = 3,
    [EVENT_THEFAMOUSDIGGER]                            = 3,
    [EVENT_LAVACAVES]                                  = 2,
    [EVENT_THEMASTEOFSKIES]                            = 4,
    [EVENT_WHATSAFUNGA]                                = 3,
    [EVENT_MONSTERHUNT]                                = 3,
    [EVENT_DEATHFRUITJUICE]                            = 3,
    [EVENT_PLANTAFLOWERGARDEN]                         = 4,
    [EVENT_TEARSFROMAFLOWER]                           = 4,
    [EVENT_SMILE]                                      = 2,
    [EVENT_CRYBABY]                                    = 2,
    [EVENT_CANTSTOPCRYING]                             = 3,
    [EVENT_THEREDFORTUNETELLER]                        = 2,
    [EVENT_APSLOTMACHINE]                              = 0,
    [EVENT_WHERESTHEBABYMOUSE]                         = 2,
    [EVENT_SOMECHEESEPLEASE]                           = 5,
    [EVENT_APOINTSHOW]                                 = 0,
    [EVENT_ADRINKFORGOWNUPS]                           = 2,
    [EVENT_ROADTOBACCUSLAKE]                           = 2,
    [EVENT_ASMALLKEYHOLE]                              = 3,
    [EVENT_ABABYSBRIDGE]                               = 0,
    [EVENT_THEMOUSEPIGBAG]                             = 2,
    [EVENT_THEHAUNTEDMANSION]                          = 6,
    [EVENT_ALARGEKEYHOLE]                              = 3,
    [EVENT_PAINTINGOFABIGKEY]                          = 3,
    [EVENT_BREAKTHEMAGICEGG]                           = 3,
    [EVENT_REDHIDDENPOWERS]                            = 5,
    [EVENT_THEELDERREQUEST]                            = 0,
    [EVENT_LETSLEARNWORDS2]                            = 0,
    [EVENT_JUNGLEOFTHEMASAKARITRIBE]                   = 0,
    [EVENT_TREEOFKNOWLEDGEKNOWS]                       = 2,
    [EVENT_THEPUMPROCKS]                               = 5,
    [EVENT_AREFRESHINGDRINK]                           = 3,
    [EVENT_INEEDATEARBOTTLE]                           = 3,
    [EVENT_THESTOLENPICTUREBOOKOFTHEISLAND]            = 0,
    [EVENT_DECIPHERSCRIBBLEINSLAND]                    = 0,
    [EVENT_SECRETOFTHEISLAND1]                         = 0,
    [EVENT_SECRETOFTHEISLAND2]                         = 0,
    [EVENT_SECRETOFTHEISLAND3]                         = 0,
    [EVENT_SECRETOFTHEISLAND4]                         = 0,
    [EVENT_SECRETOFTHEISLAND5]                         = 0,
    [EVENT_WENEEDPOWER]                                = 3,
    [EVENT_CATCHTHEELECTRICITY]                        = 0,
    [EVENT_ANINCIDENTFINDTHECULPRIT]                   = 0,
    [EVENT_WONDERSOFTHEBLACKWATER]                     = 2,
    [EVENT_THECIVILIZATIONMACHINE]                     = 1,
    [EVENT_FINDCHARLES]                                = 2,
    [EVENT_WHATSUNDERTHEFOREST]                        = 3,
    [EVENT_THE100FLOWERFOREST]                         = 6,
    [EVENT_THEBOSSTREASURE]                            = 4,
    [EVENT_IMSOHUNGRY]                                 = 3,
    [EVENT_THERUSTYSTEELCAR]                           = 3,
    [EVENT_UNKNOWN21]                                  = 0,
    [EVENT_THEDEEPJUNGLEPIG]                           = 6,
    [EVENT_HEALINGHERBSFORBARON]                       = 2,
    [EVENT_DELICIOUSKNOWLEDGEFRUIT]                    = 2,
    [EVENT_SEAWEEDFORYOURHEALTH]                       = 2,
    [EVENT_UNKNOWN22]                                  = 0,
    [EVENT_BLUEHIDDENPOWERS]                           = 5,
    [EVENT_THEPIGSVILLAGE]                             = 0,
    [EVENT_THEHOUSEWITHWHITESMOKE]                     = 0,
    [EVENT_LETSLEARNWORDS3]                            = 0,
    [EVENT_LETSGETALONG]                               = 0,
    [EVENT_ABROKENBRIDGE]                              = 0,
    [EVENT_THEGREATBOULDERINTHEVILLAGEOFTHETREEPEOPLE] = 0,
    [EVENT_WHATTIMEISIT]                               = 0,
    [EVENT_UNKNOWN30]                                  = 0,
    [EVENT_THEUNBREAKABLEGEAR]                         = 0,
    [EVENT_ABIGKEYHOLE]                                = 0,
    [EVENT_HOWAREWEGOINDTOKAEIT]                       = 0,
    [EVENT_BREAKTHERUSTYDOOR]                          = 2,
    [EVENT_THECUTEWITCH]                               = 3,
    [EVENT_FOODFORFUEL]                                = 3,
    [EVENT_INEEDABOMB]                                 = 2,
    [EVENT_UNKNOWN34]                                  = 0,
    [EVENT_UNKNOWN35]                                  = 0,
    [EVENT_UNKNOWN36]                                  = 0,
    [EVENT_THEPIGGLASSESINTHEPIGVILLAGE]               = 0,
    [EVENT_UNKNOWN38]                                  = 0,
    [EVENT_BACCUSVILLAGE]                              = 6,
    [EVENT_THEMERMAIDNECKLACE]                         = 3,
    [EVENT_BARONSSTRENGTH]                             = 4,
    [EVENT_WHATTHEWITCHLOST]                           = 3,
    [EVENT_ASAFEMUSHROOM]                              = 2,
    [EVENT_POWERUPFORTOOLS]                            = 3,
    [EVENT_UNKNOWN39]                                  = 0,
    [EVENT_THE10000YEAROLDMAN]                         = 2,
    [EVENT_MIGHTYFISHFOOD]                             = 3,
    [EVENT_LETSMAKECANDY]                              = 3,
    [EVENT_THEMERMAIDSINGINGROCK]                      = 3,
    [EVENT_THEPIRATESTREASURE]                         = 0,
    [EVENT_THEUNDERWATERPIG]                           = 2,
    [EVENT_TRICKVILLAGE]                               = 6,
    [EVENT_THETHIEFSDOOR]                              = 2,
    [EVENT_THE10MATHBEADS]                             = 3,
    [EVENT_THE5GOLDENITEMS]                            = 5,
    [EVENT_UNBREAKABLEWIRE]                            = 3,
    [EVENT_GREENHIDDENPOWERS]                          = 5,
    [EVENT_UNKNOWN41]                                  = 0,
    [EVENT_UNKNOWN42]                                  = 0,
    [EVENT_TAKETWOOFTHESE]                             = 3,
    [EVENT_IWANTABRONZEMEDAL]                          = 2,
    [EVENT_IWANTASILVERMEDAL]                          = 3,
    [EVENT_IWANTAGOLDMEDAL]                            = 4,
    [EVENT_UNKNOWN43]                                  = 0,
    [EVENT_UNKNOWN44]                                  = 0,
    [EVENT_UNKNOWN45]                                  = 0,
    [EVENT_UNKNOWN46]                                  = 0,
    [EVENT_THETHREESISTERSOFKARAKURIFORT]              = 0,
    [EVENT_LETTERSOFTHETHREESISTERS]                   = 0,
    [EVENT_UNKNOWN49]                                  = 0,
    [EVENT_UNKNOWN50]                                  = 0,
    [EVENT_MILLIONYEAROLDWISH]                         = 4,
    [EVENT_DIGLIKEAMOLE]                               = 2,
    [EVENT_THEBLUEFORTUNETELLER]                       = 2,
    [EVENT_UNKNOWN51]                                  = 0,
    [EVENT_UNKNOWN52]                                  = 0,
    [EVENT_UNKNOWN53]                                  = 0,
    [EVENT_LETSRIDETHERAFT]                            = 0,
    [EVENT_TAKEOUT]                                    = 4,
    [EVENT_UNKNOWN54]                                  = 3,
    [EVENT_WHATSTHEUNDERWATER]                         = 3,
    [EVENT_UNKNOWN55]                                  = 0,
    [EVENT_UNKNOWN56]                                  = 0,
    [EVENT_SOURCEOFEVILMAGIC]                          = 2,
    [EVENT_SEVENFRIENDS]                               = 5,
    [EVENT_UNKNOWN57]                                  = 0,
    [EVENT_THE8THEVILPIGBAG]                           = 1,
    [EVENT_THEREALEVILPIG]                             = 7,
    [EVENT_UNDERGROUNDTREASURE]                        = 3,
    [EVENT_UNKNOWN58]                                  = 0,
    [EVENT_UNKNOWN59]                                  = 0,
    [EVENT_THEFLOWERTOWER]                             = 5,
    [EVENT_UNKNOWN60]                                  = 0,
    [EVENT_AHUNGRYMONKEY]                              = 3,
    [EVENT_PEACHFLOWERGAS]                             = 2,
    [EVENT_THEEVILPIGBAG]                              = 1,
    [EVENT_BITINGPLANTFLOWER]                          = 3,
    [EVENT_WHENTHEWINDDIESDOWN]                        = 2,
    [EVENT_THEPHOENIXFAVORITE]                         = 3,
    [EVENT_THEFIREPIGBAG]                              = 3,
    [EVENT_CHARLESPANTS]                               = 0,
    [EVENT_THEHAUNTEDPIGBAG]                           = 2,
    [EVENT_THEWORLDSGREATESTSMILE]                     = 2,
    [EVENT_THEWORLDSGREATESTPOUT]                      = 2,
    [EVENT_SOMETHINGCOOKIN]                            = 5,
    [EVENT_LEAFBUTTERFLIES]                            = 5,
    [EVENT_WHEREDTHELIGHTSGO]                          = 2,
    [EVENT_WHERETHEBARRELSROLLS]                       = 4,
    [EVENT_READYSETGO]                                 = 3,
    [EVENT_AMAGICMIRROR]                               = 2,
    [EVENT_THEJUNGLEPIGBAG]                            = 2,
    [EVENT_UNKNOWN61]                                  = 0,
    [EVENT_APRECIOUSTREASURECHEST]                     = 2,
    [EVENT_UNKNOWN62]                                  = 0,
    [EVENT_THEMISTERIOUSMUSHROOM]                      = 2,
    [EVENT_LEAFSLIDER]                                 = 2,
    [EVENT_REDBLUE]                                    = 3,
    [EVENT_THETROUBLEDTHIEF]                           = 2,
    [EVENT_WHATTHETHIEFFORGOT]                         = 3,
    [EVENT_UNKNOWN63]                                  = 0,
    [EVENT_UNKNOWN64]                                  = 0,
    [EVENT_UNKNOWN65]                                  = 0,
    [EVENT_UNKNOWN66]                                  = 0,
    [EVENT_UNKNOWN67]                                  = 0,
    [EVENT_UNKNOWN68]                                  = 0,
    [EVENT_UNKNOWN69]                                  = 0,
    [EVENT_UNKNOWN70]                                  = 0,
};

u8* D_800776D0[20] = {
    [AREA00_VILLAGEOFALLBEGINNINGS]          = D_80077428,
    [AREA01_DWARFFOREST]                     = D_80077428,
    [AREA02_DWARFVILLAGE]                    = D_80077428,
    [AREA03_PHOENIXMOUNTAIN]                 = D_80077428,
    [AREA04_HAUNTEDMANSION]                  = D_80077428,
    [AREA05_BACCUSVILLAGE]                   = D_80077428,
    [AREA06_DIRTMOTOCROSS]                   = D_80077428,
    [AREA07_DWARFFORESTPURIFIED]             = D_80077428,
    [AREA08_BACCUSLAKE]                      = D_80077428,
    [AREA09_MUSHROOMVILLAGE]                 = D_80077428,
    [AREA10_DEEPJUNGLE]                      = D_80077428,
    [AREA11_VILLAGEOFCIVILIZATION]           = D_80077428,
    [AREA12_HAUNTEDMANSIONPURIFIED]          = D_80077428,
    [AREA13_PIGISLAND]                       = D_80077428,
    [AREA14_EVILPIGS]                        = D_80077428,
    [AREA15_UNKNOWN]                         = D_80077428,
    [AREA16_VILLAGEOFCIVILIZATIONCLOCKTOWER] = D_80077428,
    [AREA17_VILLAGEOFCIVILIZATIONIRONTOWER]  = D_80077428,
    [AREA18_VILLAGEOFCIVILIZATIONYCROSSING]  = D_80077428,
    [AREA19_VILLAGEOFCIVILIZATIONPURIFIED]   = D_80077428,
};

unk_80077720 D_80077720[2] = {
    { 0x5A, 0xB4 },
    { 0x96, 0x5A }
};

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", awardEventProgress);
u_char awardEventProgress(EVENT event_id, int ap_table, int state)
{
    if (ap_table == 0) {
        addPlayerAP(AP_TABLE[EVENT_STARTED_AP_TABLE[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            spawnEventTitle(event_id, 0, 0x3C, state);
            printEventMessage(event_id, 0);
            playSFX(42);
            spawnItemPickupObject(0);
        }
    } else {
        addPlayerAP(AP_TABLE[EVENT_COMPLETE_AP_TABLE[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            spawnEventTitle(event_id, 1, 1, state);
            printEventMessage(event_id, 1);
            playJingle(2);
            muteBgm();
        }
    }
    return GAME.event[event_id];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", setEventStarted);
u_char setEventStarted(EVENT event_id, int arg1, int state)
{
    if (GAME.event[event_id] == 0) {
        if (event_id == EVENT_THE100YEAROLDWISEMAN) {
            if (*(u_long*)&GAME.selectedArea == (AREA00_VILLAGEOFALLBEGINNINGS << 16 | AREA00_SECTION00_VILLAGEOFALLBEGINNINGS)) {
                GAME.event[event_id] += 1;
            }
        } else {
            GAME.event[event_id] += 1;
        }
        addPlayerAP(AP_TABLE[EVENT_STARTED_AP_TABLE[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            spawnEventTitle(event_id, 0, 0x3C, state);
            printEventMessage(event_id, 0);
            playSFX(42);
            spawnItemPickupObject(0);
        }        
    }
    return GAME.event[event_id];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", setEventComplete);
u_char setEventComplete(EVENT event_id, int state)
{
    if (GAME.event[event_id] != 0xFF) {
        GAME.event[event_id] = 0xFF;
        addPlayerAP(AP_TABLE[EVENT_COMPLETE_AP_TABLE[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            spawnEventTitle(event_id, 1, 1, state);
            printEventMessage(event_id, 1);
            playJingle(2);
            muteBgm();
        }
    }
    return GAME.event[event_id];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", getEventState);
u_char getEventState(EVENT event_id)
{
    return GAME.event[event_id];
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", spawnEventTitle);
int spawnEventTitle(int event_id, int completed, int duration, int state)
{
    s16 x;
    s16 y;
    u8* src;
    u8 idx;
    s8** tbl;
    s8* p;
    u8* obj;
    int i;
    int done;
    int once;
    int n;
    u16* q;
    int temp;
    int* hdr;

    if (event_id == 1) {
        duration = 1;
        x = D_800A53AA - D_800A38C2;
        y = (u16)D_800A53AE - *(u16*)0x1F8000F2;
    }
    src = *(u8**)0x1F80039C;
    src += *(u16*)(src + 8);
    idx = D_800776D0[GAME.selectedArea][event_id];
    if (idx == 0xFF) {
        q = (u16*)(src + 2);
    } else {
        q = (u16*)(src + idx * 2);
    }
    src += *q;
    i = 0;
    switch (GAME.selectedArea) {
    case 0:
        tbl = D_80139330;
        break;
    case 1:
        tbl = D_8013CC1C;
        break;
    case 2:
        switch (D_8009BCCA) {
        case 0:
            tbl = D_800F00BC;
            break;
        case 1:
        case 2:
        case 4:
        case 5:
            tbl = D_8011E3A0;
            break;
        case 3:
            tbl = D_800F077C;
            break;
        }
        break;
    case 3:
        tbl = D_80137998;
        break;
    case 4:
        tbl = D_80132CAC;
        break;
    case 5:
        switch (D_8009BCCA) {
        case 0:
        case 2:
            tbl = D_80102000;
            break;
        case 1:
        case 3:
            tbl = D_80119334;
            break;
        }
        break;
    case 6:
        tbl = D_80121BE0;
        break;
    case 7:
        tbl = D_80118018;
        break;
    case 8:
        switch (D_8009BCCA) {
        case 0:
        case 2:
            tbl = D_80102000;
            break;
        case 1:
        case 3:
            tbl = D_801177F8;
            break;
        }
        break;
    case 9:
        tbl = D_8012CB9C;
        break;
    case 10:
        tbl = D_80130DD8;
        break;
    case 11:
        tbl = D_8011B4C8;
        break;
    case 12:
        tbl = D_80118C38;
        break;
    case 13:
        tbl = D_80119B44;
        break;
    case 14:
        tbl = D_80128018;
        break;
    case 16:
        tbl = D_8011A5CC;
        break;
    case 17:
        tbl = D_8011B2A8;
        break;
    case 18:
        tbl = D_8011BDC0;
        break;
    case 19:
        switch (D_8009BCCA) {
        case 0:
            tbl = D_800F00BC;
            break;
        case 1:
            tbl = D_8011E3A0;
            break;
        case 2:
            tbl = D_80102000;
            break;
        }
        break;
    }
    done = 0;
    p = tbl[event_id];
    D_8009BC9B = 1;
    once = 0;
    for (; p[0] != -1; p += 4) {
        obj = (u8*)allocObjectLayer8();
        if (obj != NULL) {
            obj[0] = 1;
            obj[2] = 1;
            obj[0xD] = 1;
            *(s16*)(obj + 8) = 0x7D16;
            obj[3] = completed;
            *(s16*)(obj + 0x1E) = 0;
            *(s8*)(obj + 0xF) = -0x5A;
            *(s16*)(obj + 0x2E) = 1;
            temp = obj[0x1C] | 0x80;
            obj[0x1C] = temp;
            *(s16*)(obj + 0x20) = duration;
            temp = (int)(&SCRATCHPAD + 0x33C);
            hdr = *(int* volatile*)temp;
            temp = (int)*(int* volatile*)temp;
            temp += hdr[1];
            *(int*)(obj + 0xA0) = temp;
            if (event_id == 1) {
                *(int*)(obj + 0x10) = (x - 0xA0) << 16;
                *(int*)(obj + 0x14) = y << 16;
                *(int*)(obj + 0x18) = (((s16*)PLAYER)[0xD] + 10) << 16;
                *(int*)(obj + 0x30) = (x - 0xA0) << 16;
                *(int*)(obj + 0x34) = y << 16;
                *(int*)(obj + 0x38) = (((s16*)PLAYER)[0xD] + 10) << 16;
            } else {
                *(int*)(obj + 0x10) = D_800774F0[1] << 16;
                *(int*)(obj + 0x14) = D_800774F0[2] << 16;
                *(int*)(obj + 0x18) = 0;
                *(int*)(obj + 0x30) = D_800774F0[1] << 16;
                *(int*)(obj + 0x34) = D_800774F0[2] << 16;
                *(int*)(obj + 0x38) = 0;
            }
            obj[0xC] = i;
            n = p[3] & 0xF;
            *(u16*)(obj + 0xBC) = *(u16*)src & 0xFFF;
            *(u16*)(obj + 0xC0) = D_800774F8[n];
            *(s16*)(obj + 0xC4) = p[1] * 10;
            *(s16*)(obj + 0xC6) = p[2] * 14;
            *(u16*)(obj + 0xC8) = D_80077508[n].unk0;
            *(u16*)(obj + 0xCA) = D_80077508[n].unk2;
            *(u16*)(obj + 0xCC) = (u8)p[3];
            *(u16*)(obj + 0xCE) = 0;
            i++;
            src += 2;
            if (D_8009C618 != 3 && done == 0) {
                if (state != 0) {
                    *(u16*)(obj + 0xD0) = D_8009BC98[0xF];
                    D_8009BC98[0xF] = 1;
                    D_8009BCAA = 1;
                    if (state != 4 && (PLAYER[0x9E] == 0 || PLAYER[0xAC] < 2)) {
                        PLAYER[4] = 5;
                        PLAYER[5] = 0;
                        PLAYER[6] = 0;
                        PLAYER[7] = 0;
                    } else if (D_8009BCA8 == 0) {
                        D_8009BCA6 = 1;
                    }
                    *(u16*)(obj + 0xCE) = state;
                }
                *(u16*)(obj + 0xCE) |= 0x8000;
                done = 1;
            }
            if (event_id == 0xF && completed == 1 && once == 0) {
                once = 1;
                *(u16*)(obj + 0xD2) = 0x27;
                *(u16*)(obj + 0xCE) = 0x8002;
            } else {
                *(u16*)(obj + 0xD2) = 0;
            }
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", acquireSpriteSlot);
short acquireSpriteSlot(int id)
{
    RECT rect;
    int i;
    int freeSlot;
    int j;
    int k;
    short slot;
    u16* src;
    u16* dst;
    u16 w;
    u16 h;
    u16 a;
    u16 b;
    DR_LOAD* load;

    freeSlot = -1;
    for (i = 0; i < 0x30; i++) {
        if (SPRITE_SLOTS[i].id == id) {
            SPRITE_SLOTS[i].refCount++;
            return i;
        }
        if (SPRITE_SLOTS[i].id == -1) {
            freeSlot = i;
        }
    }

    slot = freeSlot;
    if (slot == -1) {
        return -1;
    }

    SPRITE_SLOTS[slot].refCount = 1;
    src = ((scratchpad*)PSX_SCRATCH)->unk39C;
    dst = (u16*)(id * 2 + (int)src);
    src = (u16*)((u8*)src + dst[0x48]);
    w = *src++;
    h = *src++;
    a = *src++;
    b = *src++;
    SPRITE_SLOTS[slot].id = id;
    SPRITE_SLOTS[slot].val[4] = 0;
    SPRITE_SLOTS[slot].val[2] = a;
    SPRITE_SLOTS[slot].val[3] = h;
    SPRITE_SLOTS[slot].val[5] = b;
    for (k = 0; k < 4; k++) {
        load = (DR_LOAD*)D_1F800164;
        setRECT(&rect, SPRITE_SLOTS[slot].val[0], SPRITE_SLOTS[slot].val[1] + k * (h >> 2), w, h >> 2);
        SetDrawLoad(load, &rect);
        dst = (u16*)load->p;
        for (j = 0; j < w * (u16)(h >> 2); j++) {
            *dst++ = *src++;
        }
        addPrim(D_1F8001E0 + 4, load);
        D_1F800164 += sizeof(DR_LOAD);
    }
    return freeSlot;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", printEventMessage);
void printEventMessage(int event_id, int completed)
{
    int digits[8];
    int ap;
    int n;
    int count;
    int i;
    u8* obj;

    if (completed == 0) {
        ap = AP_TABLE[EVENT_STARTED_AP_TABLE[event_id]];
    } else {
        ap = AP_TABLE[EVENT_COMPLETE_AP_TABLE[event_id]];
    }
    if (ap == 0) {
        return;
    }

    n = ap;
    digits[0] = n % 10;
    n /= 10;
    digits[1] = n % 10;
    n /= 10;
    digits[2] = n % 10;
    n /= 10;
    digits[3] = n % 10;
    n /= 10;
    digits[4] = n % 10;
    n /= 10;
    digits[5] = n % 10;
    n /= 10;
    digits[6] = n % 10;
    n /= 10;
    digits[7] = n % 10;

    if (ap < 10) {
        count = 1;
    } else if (ap < 100) {
        count = 2;
    } else if (ap < 1000) {
        count = 3;
    } else if (ap < 10000) {
        count = 4;
    } else if (ap < 100000) {
        count = 5;
    } else if (ap < 1000000) {
        count = 6;
    } else if (ap < 10000000) {
        count = 7;
    } else {
        count = 8;
    }

    for (i = 0; i < count; i++) {
        obj = allocObjectLayer3();
        if (obj != NULL) {
            int active = 1;

            obj[2] = 0x22;
            obj[0] = active;
            obj[3] = completed;
            obj[0xC] = digits[i];
            *(s16*)(obj + 8) = 0x7D16;
            *(int*)(obj + 0x10) = (count * 8 + 160 - i * 16) << 16;
            obj[0xD] = 1;
            *(s16*)(obj + 0x2E) = 1;
            obj[0xF] = 0;
            *(int*)(obj + 0x14) = 0x900000;
            *(int*)(obj + 0x18) = 0;
            obj[0x1C] |= 0x80;
            *(u16*)(obj + 0xB4) = D_80077720[completed].unk0;
            *(u16*)(obj + 0xB6) = D_80077720[completed].unk2;
        }
    }
}
