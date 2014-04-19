#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000;
int arr[MAXN+10];
bool isUsed[8];
typedef long long ll;


void preprocess() {

	for(int i=10; i <= MAXN; i++) {
		arr[i] = -1;
	}
	arr[174280] = 174280;
arr[174820] = 174820;
arr[126] = 126;
arr[1260] = 1260;
arr[12600] = 12600;
arr[126000] = 126000;
arr[258795] = 258795;
arr[1530] = 1530;
arr[15030] = 15030;
arr[15300] = 15300;
arr[123840] = 123840;
arr[128430] = 128430;
arr[135450] = 135450;
arr[150030] = 150030;
arr[150300] = 150300;
arr[153000] = 153000;
arr[154350] = 154350;
arr[213750] = 213750;
arr[217530] = 217530;
arr[1435] = 1435;
arr[14350] = 14350;
arr[143500] = 143500;
arr[289674] = 289674;
arr[12550] = 12550;
arr[102550] = 102550;
arr[105250] = 105250;
arr[125050] = 125050;
arr[125500] = 125500;
arr[125950] = 125950;
arr[129550] = 129550;
arr[251050] = 251050;
arr[255100] = 255100;
arr[153] = 153;
arr[1530] = 1530;
arr[15300] = 15300;
arr[153000] = 153000;
arr[1260] = 1260;
arr[12060] = 12060;
arr[12600] = 12600;
arr[120060] = 120060;
arr[120600] = 120600;
arr[126000] = 126000;
arr[127620] = 127620;
arr[152460] = 152460;
arr[162720] = 162720;
arr[446760] = 446760;
arr[263736] = 263736;
arr[6880] = 6880;
arr[37840] = 37840;
arr[68800] = 68800;
arr[118480] = 118480;
arr[378400] = 378400;
arr[397840] = 397840;
arr[521680] = 521680;
arr[688000] = 688000;
arr[2187] = 2187;
arr[21870] = 21870;
arr[218700] = 218700;
arr[688] = 688;
arr[6880] = 6880;
arr[68800] = 68800;
arr[688000] = 688000;
arr[1827] = 1827;
arr[18270] = 18270;
arr[182700] = 182700;
arr[31590] = 31590;
arr[112590] = 112590;
arr[157950] = 157950;
arr[315090] = 315090;
arr[315900] = 315900;
arr[517590] = 517590;
arr[562950] = 562950;
arr[671490] = 671490;
arr[711990] = 711990;
arr[789750] = 789750;
arr[1395] = 1395;
arr[13950] = 13950;
arr[139500] = 139500;
arr[268398] = 268398;
arr[129640] = 129640;
arr[11844] = 11844;
arr[118440] = 118440;
arr[13950] = 13950;
arr[105750] = 105750;
arr[139500] = 139500;
arr[1206] = 1206;
arr[10251] = 10251;
arr[12060] = 12060;
arr[102510] = 102510;
arr[120600] = 120600;
arr[105264] = 105264;
arr[125460] = 125460;
arr[1260] = 1260;
arr[12600] = 12600;
arr[18270] = 18270;
arr[105210] = 105210;
arr[126000] = 126000;
arr[182700] = 182700;
arr[190260] = 190260;
arr[192150] = 192150;
arr[18225] = 18225;
arr[182250] = 182250;
arr[17325] = 17325;
arr[173250] = 173250;
arr[156240] = 156240;
arr[12546] = 12546;
arr[125460] = 125460;
arr[1255] = 1255;
arr[12550] = 12550;
arr[21586] = 21586;
arr[125500] = 125500;
arr[215860] = 215860;
arr[104260] = 104260;
arr[21870] = 21870;
arr[218700] = 218700;
arr[18265] = 18265;
arr[182650] = 182650;
arr[15300] = 15300;
arr[150300] = 150300;
arr[153000] = 153000;
arr[296320] = 296320;
arr[13243] = 13243;
arr[132430] = 132430;
arr[14350] = 14350;
arr[140350] = 140350;
arr[143500] = 143500;
arr[253750] = 253750;
arr[3159] = 3159;
arr[31590] = 31590;
arr[315900] = 315900;
arr[336960] = 336960;
arr[17437] = 17437;
arr[174370] = 174370;
arr[135837] = 135837;
arr[10426] = 10426;
arr[14035] = 14035;
arr[104260] = 104260;
arr[140350] = 140350;
arr[14350] = 14350;
arr[132430] = 132430;
arr[143500] = 143500;
arr[145314] = 145314;
arr[163944] = 163944;
arr[284760] = 284760;
arr[131242] = 131242;
arr[133245] = 133245;
arr[134725] = 134725;
arr[153436] = 153436;
arr[37845] = 37845;
arr[378450] = 378450;
arr[124483] = 124483;
arr[146137] = 146137;
arr[174370] = 174370;
arr[254740] = 254740;
arr[3784] = 3784;
arr[37840] = 37840;
arr[378400] = 378400;
arr[42898] = 42898;
arr[428980] = 428980;
arr[126846] = 126846;
arr[193945] = 193945;
arr[125500] = 125500;
arr[1503] = 1503;
arr[10521] = 10521;
arr[15030] = 15030;
arr[105210] = 105210;
arr[150300] = 150300;
arr[1530] = 1530;
arr[15300] = 15300;
arr[102510] = 102510;
arr[125460] = 125460;
arr[153000] = 153000;
arr[105264] = 105264;
arr[241564] = 241564;
arr[336550] = 336550;
arr[123354] = 123354;
arr[456840] = 456840;
arr[25474] = 25474;
arr[254740] = 254740;
arr[125433] = 125433;
arr[45864] = 45864;
arr[458640] = 458640;
arr[475380] = 475380;
arr[156289] = 156289;
arr[245182] = 245182;
arr[284598] = 284598;
arr[36855] = 36855;
arr[152685] = 152685;
arr[368550] = 368550;
arr[135828] = 135828;
arr[498550] = 498550;
arr[193257] = 193257;
arr[315594] = 315594;
arr[12600] = 12600;
arr[120600] = 120600;
arr[126000] = 126000;
arr[263074] = 263074;
arr[152608] = 152608;
arr[286416] = 286416;
arr[125460] = 125460;
arr[326452] = 326452;
arr[48672] = 48672;
arr[486720] = 486720;
arr[213466] = 213466;
arr[126027] = 126027;
arr[368550] = 368550;
arr[538650] = 538650;
arr[33655] = 33655;
arr[136525] = 136525;
arr[336550] = 336550;
arr[41665] = 41665;
arr[341653] = 341653;
arr[416650] = 416650;
arr[182650] = 182650;
arr[416650] = 416650;
arr[457600] = 457600;
arr[568750] = 568750;
arr[638950] = 638950;
arr[15624] = 15624;
arr[156240] = 156240;
arr[392566] = 392566;
arr[216733] = 216733;
arr[28476] = 28476;
arr[217638] = 217638;
arr[284760] = 284760;
arr[629680] = 629680;
arr[365638] = 365638;
arr[233896] = 233896;
arr[110758] = 110758;
arr[117067] = 117067;
arr[45760] = 45760;
arr[457600] = 457600;
arr[10575] = 10575;
arr[105750] = 105750;
arr[304717] = 304717;
arr[197725] = 197725;
arr[673920] = 673920;
arr[25375] = 25375;
arr[116725] = 116725;
arr[129775] = 129775;
arr[253750] = 253750;
arr[312475] = 312475;
arr[173250] = 173250;
arr[679500] = 679500;
arr[175329] = 175329;
arr[516879] = 516879;
arr[115672] = 115672;
arr[486720] = 486720;
arr[172822] = 172822;
arr[68800] = 68800;
arr[378400] = 378400;
arr[688000] = 688000;
arr[108135] = 108135;
arr[180225] = 180225;
arr[201852] = 201852;
arr[260338] = 260338;
arr[205785] = 205785;
arr[21870] = 21870;
arr[182250] = 182250;
arr[218700] = 218700;
arr[226872] = 226872;
arr[125248] = 125248;
arr[386415] = 386415;
arr[47538] = 47538;
arr[475380] = 475380;
arr[118440] = 118440;
arr[458640] = 458640;
arr[226498] = 226498;
arr[49855] = 49855;
arr[414895] = 414895;
arr[498550] = 498550;
arr[45684] = 45684;
arr[456840] = 456840;
arr[251896] = 251896;
arr[53865] = 53865;
arr[538650] = 538650;
arr[6880] = 6880;
arr[68800] = 68800;
arr[215860] = 215860;
arr[688000] = 688000;
arr[338296] = 338296;
arr[186624] = 186624;
arr[567648] = 567648;
arr[18270] = 18270;
arr[182700] = 182700;
arr[378450] = 378450;
arr[56875] = 56875;
arr[568750] = 568750;
arr[738468] = 738468;
arr[378418] = 378418;
arr[218488] = 218488;
arr[428980] = 428980;
arr[384912] = 384912;
arr[416988] = 416988;
arr[489159] = 489159;
arr[180297] = 180297;
arr[489955] = 489955;
arr[315900] = 315900;
arr[789250] = 789250;
arr[19026] = 19026;
arr[67950] = 67950;
arr[190260] = 190260;
arr[679500] = 679500;
arr[809964] = 809964;
arr[404968] = 404968;
arr[319059] = 319059;
arr[809919] = 809919;
arr[19215] = 19215;
arr[192150] = 192150;
arr[12964] = 12964;
arr[29632] = 29632;
arr[62968] = 62968;
arr[129640] = 129640;
arr[162976] = 162976;
arr[229648] = 229648;
arr[262984] = 262984;
arr[296320] = 296320;
arr[329656] = 329656;
arr[362992] = 362992;
arr[429664] = 429664;
arr[529672] = 529672;
arr[629680] = 629680;
arr[729688] = 729688;
arr[829696] = 829696;
arr[792585] = 792585;
arr[13950] = 13950;
arr[139500] = 139500;
arr[33696] = 33696;
arr[67392] = 67392;
arr[336960] = 336960;
arr[673920] = 673920;
arr[136948] = 136948;
arr[447916] = 447916;
arr[146952] = 146952;
arr[841995] = 841995;
arr[346968] = 346968;
arr[156915] = 156915;
arr[319536] = 319536;
arr[559188] = 559188;
arr[815958] = 815958;
arr[536539] = 536539;
arr[789525] = 789525;
arr[329346] = 329346;
arr[736695] = 736695;
arr[369189] = 369189;
arr[371893] = 371893;
arr[312975] = 312975;
arr[211896] = 211896;
arr[361989] = 361989;
arr[63895] = 63895;
arr[638950] = 638950;
arr[794088] = 794088;
arr[939658] = 939658;
arr[769792] = 769792;
arr[103968] = 103968;
arr[116928] = 116928;
arr[11259] = 11259;
arr[112590] = 112590;
arr[118440] = 118440;
arr[11848] = 11848;
arr[118480] = 118480;
arr[124488] = 124488;
arr[139500] = 139500;
arr[118575] = 118575;
arr[107163] = 107163;
arr[171598] = 171598;
arr[15795] = 15795;
arr[157950] = 157950;
arr[112468] = 112468;
arr[158193] = 158193;
arr[115699] = 115699;
arr[12006] = 12006;
arr[102051] = 102051;
arr[120060] = 120060;
arr[12060] = 12060;
arr[102510] = 102510;
arr[120600] = 120600;
arr[10255] = 10255;
arr[102550] = 102550;
arr[105264] = 105264;
arr[105723] = 105723;
arr[12600] = 12600;
arr[126000] = 126000;
arr[182700] = 182700;
arr[10525] = 10525;
arr[105250] = 105250;
arr[12762] = 12762;
arr[127620] = 127620;
arr[184126] = 184126;
arr[192685] = 192685;
arr[121576] = 121576;
arr[182250] = 182250;
arr[173250] = 173250;
arr[173925] = 173925;
arr[179325] = 179325;
arr[172246] = 172246;
arr[124542] = 124542;
arr[125460] = 125460;
arr[12505] = 12505;
arr[102541] = 102541;
arr[125050] = 125050;
arr[215086] = 215086;
arr[12550] = 12550;
arr[125500] = 125500;
arr[215860] = 215860;
arr[12595] = 12595;
arr[125950] = 125950;
arr[15246] = 15246;
arr[152460] = 152460;
arr[12955] = 12955;
arr[129550] = 129550;
arr[210681] = 210681;
arr[122764] = 122764;
arr[212868] = 212868;
arr[246928] = 246928;
arr[218700] = 218700;
arr[127417] = 127417;
arr[176215] = 176215;
arr[16272] = 16272;
arr[162720] = 162720;
arr[145273] = 145273;
arr[236758] = 236758;
arr[182065] = 182065;
arr[182650] = 182650;
arr[268398] = 268398;
arr[139824] = 139824;
arr[153000] = 153000;
arr[141345] = 141345;
arr[283198] = 283198;
arr[132430] = 132430;
arr[123538] = 123538;
arr[231673] = 231673;
arr[134275] = 134275;
arr[243175] = 243175;
arr[143500] = 143500;
arr[31509] = 31509;
arr[315090] = 315090;
arr[31590] = 31590;
arr[315900] = 315900;
arr[145345] = 145345;
arr[281736] = 281736;
arr[336195] = 336195;
arr[263736] = 263736;
arr[107329] = 107329;
arr[307183] = 307183;
arr[174370] = 174370;
arr[174793] = 174793;
arr[347913] = 347913;
arr[328864] = 328864;
arr[376992] = 376992;
arr[104026] = 104026;
arr[140035] = 140035;
arr[104260] = 104260;
arr[140350] = 140350;
arr[143500] = 143500;
arr[12384] = 12384;
arr[123840] = 123840;
arr[149364] = 149364;
arr[214506] = 214506;
arr[215424] = 215424;
arr[12843] = 12843;
arr[128430] = 128430;
arr[267034] = 267034;
arr[384925] = 384925;
arr[378450] = 378450;
arr[314743] = 314743;
arr[13545] = 13545;
arr[135450] = 135450;
arr[449955] = 449955;
arr[346725] = 346725;
arr[390847] = 390847;
arr[122746] = 122746;
arr[37840] = 37840;
arr[378400] = 378400;
arr[428980] = 428980;
arr[465984] = 465984;
arr[102942] = 102942;
arr[39784] = 39784;
arr[397840] = 397840;
arr[15003] = 15003;
arr[105021] = 105021;
arr[150030] = 150030;
arr[15030] = 15030;
arr[105210] = 105210;
arr[150300] = 150300;
arr[25105] = 25105;
arr[251050] = 251050;
arr[15300] = 15300;
arr[153000] = 153000;
arr[25510] = 25510;
arr[255100] = 255100;
arr[15435] = 15435;
arr[154350] = 154350;
arr[217854] = 217854;
arr[215455] = 215455;
arr[223524] = 223524;
arr[495328] = 495328;
arr[465088] = 465088;
arr[254740] = 254740;
arr[458640] = 458640;
arr[519745] = 519745;
arr[415575] = 415575;
arr[535968] = 535968;
arr[236754] = 236754;
arr[468535] = 468535;
arr[352966] = 352966;
arr[530379] = 530379;
arr[526792] = 526792;
arr[51759] = 51759;
arr[155277] = 155277;
arr[517590] = 517590;
arr[150826] = 150826;
arr[245448] = 245448;
arr[368550] = 368550;
arr[126000] = 126000;
arr[108216] = 108216;
arr[108864] = 108864;
arr[146520] = 146520;
arr[256410] = 256410;
arr[486720] = 486720;
arr[162526] = 162526;
arr[612598] = 612598;
arr[256414] = 256414;
arr[56295] = 56295;
arr[562950] = 562950;
arr[132615] = 132615;
arr[297463] = 297463;
arr[336550] = 336550;
arr[416065] = 416065;
arr[416650] = 416650;
arr[462672] = 462672;
arr[116478] = 116478;
arr[156024] = 156024;
arr[156240] = 156240;
arr[52168] = 52168;
arr[521680] = 521680;
arr[284760] = 284760;
arr[268398] = 268398;
arr[289674] = 289674;
arr[105075] = 105075;
arr[457600] = 457600;
arr[105750] = 105750;
arr[490176] = 490176;
arr[21375] = 21375;
arr[213750] = 213750;
arr[253750] = 253750;
arr[21753] = 21753;
arr[152271] = 152271;
arr[217530] = 217530;
arr[623758] = 623758;
arr[263736] = 263736;
arr[375156] = 375156;
arr[573768] = 573768;
arr[375615] = 375615;
arr[710496] = 710496;
arr[44676] = 44676;
arr[446760] = 446760;
arr[67149] = 67149;
arr[671490] = 671490;
arr[287356] = 287356;
arr[632875] = 632875;
arr[678892] = 678892;
arr[368784] = 368784;
arr[667876] = 667876;
arr[71199] = 71199;
arr[711990] = 711990;
arr[688000] = 688000;
arr[208624] = 208624;
arr[450688] = 450688;
arr[218700] = 218700;
arr[121815] = 121815;
arr[114268] = 114268;
arr[439582] = 439582;
arr[341284] = 341284;
arr[475380] = 475380;
arr[475893] = 475893;
arr[328419] = 328419;
arr[227448] = 227448;
arr[498550] = 498550;
arr[456840] = 456840;
arr[538650] = 538650;
arr[68800] = 68800;
arr[688000] = 688000;
arr[180621] = 180621;
arr[611878] = 611878;
arr[588676] = 588676;
arr[182700] = 182700;
arr[809937] = 809937;
arr[17428] = 17428;
arr[174280] = 174280;
arr[226876] = 226876;
arr[279328] = 279328;
arr[17482] = 17482;
arr[174820] = 174820;
arr[568750] = 568750;
arr[78975] = 78975;
arr[789750] = 789750;
arr[283648] = 283648;
arr[419287] = 419287;
arr[124978] = 124978;
arr[859968] = 859968;
arr[315490] = 315490;
arr[207391] = 207391;
arr[515907] = 515907;
arr[190260] = 190260;
arr[679500] = 679500;
arr[899019] = 899019;
arr[190827] = 190827;
arr[191205] = 191205;
arr[192150] = 192150;
arr[192717] = 192717;
arr[404932] = 404932;
arr[101299] = 101299;
arr[194229] = 194229;
arr[129514] = 129514;
arr[129640] = 129640;
arr[296320] = 296320;
arr[629680] = 629680;
arr[798682] = 798682;
arr[139500] = 139500;
arr[531297] = 531297;
arr[336960] = 336960;
arr[673920] = 673920;
arr[393246] = 393246;
arr[442975] = 442975;
arr[614965] = 614965;
arr[671944] = 671944;
arr[258795] = 258795;
arr[692712] = 692712;
arr[163795] = 163795;
arr[549765] = 549765;
arr[665919] = 665919;
arr[697248] = 697248;
arr[687919] = 687919;
arr[611793] = 611793;
arr[960988] = 960988;
arr[638950] = 638950;
arr[649638] = 649638;
arr[936985] = 936985;
arr[112509] = 112509;
arr[112590] = 112590;
arr[104368] = 104368;
arr[129438] = 129438;
arr[118408] = 118408;
arr[118480] = 118480;
arr[119848] = 119848;
arr[138784] = 138784;
arr[157950] = 157950;
arr[108126] = 108126;
arr[108612] = 108612;
arr[116496] = 116496;
arr[118926] = 118926;
arr[120006] = 120006;
arr[120060] = 120060;
arr[100255] = 100255;
arr[120600] = 120600;
arr[100525] = 100525;
arr[120762] = 120762;
arr[121086] = 121086;
arr[102505] = 102505;
arr[102550] = 102550;
arr[102595] = 102595;
arr[102955] = 102955;
arr[165208] = 165208;
arr[187029] = 187029;
arr[126000] = 126000;
arr[105025] = 105025;
arr[126108] = 126108;
arr[105250] = 105250;
arr[105295] = 105295;
arr[168520] = 168520;
arr[189702] = 189702;
arr[127620] = 127620;
arr[192375] = 192375;
arr[129564] = 129564;
arr[109525] = 109525;
arr[213759] = 213759;
arr[125005] = 125005;
arr[125050] = 125050;
arr[125095] = 125095;
arr[150246] = 150246;
arr[125500] = 125500;
arr[150624] = 150624;
arr[125950] = 125950;
arr[125995] = 125995;
arr[152406] = 152406;
arr[152460] = 152460;
arr[152946] = 152946;
arr[231579] = 231579;
arr[129505] = 129505;
arr[129550] = 129550;
arr[129595] = 129595;
arr[129955] = 129955;
arr[236925] = 236925;
arr[132565] = 132565;
arr[132655] = 132655;
arr[162072] = 162072;
arr[162720] = 162720;
arr[172386] = 172386;
arr[258795] = 258795;
arr[156325] = 156325;
arr[293625] = 293625;
arr[163255] = 163255;
arr[314199] = 314199;
arr[315009] = 315009;
arr[315090] = 315090;
arr[315900] = 315900;
arr[285376] = 285376;
arr[297832] = 297832;
arr[355995] = 355995;
arr[238968] = 238968;
arr[120384] = 120384;
arr[241506] = 241506;
arr[120843] = 120843;
arr[246150] = 246150;
arr[123084] = 123084;
arr[123840] = 123840;
arr[123894] = 123894;
arr[381429] = 381429;
arr[128403] = 128403;
arr[128430] = 128430;
arr[342688] = 342688;
arr[128943] = 128943;
arr[346288] = 346288;
arr[393417] = 393417;
arr[394875] = 394875;
arr[135045] = 135045;
arr[135450] = 135450;
arr[136854] = 136854;
arr[368104] = 368104;
arr[416259] = 416259;
arr[373864] = 373864;
arr[378400] = 378400;
arr[286974] = 286974;
arr[143739] = 143739;
arr[143793] = 143793;
arr[289674] = 289674;
arr[145683] = 145683;
arr[397840] = 397840;
arr[399784] = 399784;
arr[150003] = 150003;
arr[150030] = 150030;
arr[250105] = 250105;
arr[150300] = 150300;
arr[250510] = 250510;
arr[150435] = 150435;
arr[251005] = 251005;
arr[251050] = 251050;
arr[251095] = 251095;
arr[153000] = 153000;
arr[255010] = 255010;
arr[255100] = 255100;
arr[256315] = 256315;
arr[154350] = 154350;
arr[259510] = 259510;
arr[263155] = 263155;
arr[488592] = 488592;
arr[435784] = 435784;
arr[163854] = 163854;
arr[164583] = 164583;
arr[493857] = 493857;
arr[451768] = 451768;
arr[457168] = 457168;
arr[517509] = 517509;
arr[517590] = 517590;
arr[295105] = 295105;
arr[295510] = 295510;
arr[312565] = 312565;
arr[312655] = 312655;
arr[562950] = 562950;
arr[315625] = 315625;
arr[316255] = 316255;
arr[520168] = 520168;
arr[520816] = 520816;
arr[325615] = 325615;
arr[521608] = 521608;
arr[521680] = 521680;
arr[326155] = 326155;
arr[618759] = 618759;
arr[210375] = 210375;
arr[210753] = 210753;
arr[213075] = 213075;
arr[213750] = 213750;
arr[571648] = 571648;
arr[142978] = 142978;
arr[217503] = 217503;
arr[217530] = 217530;
arr[446760] = 446760;
arr[446976] = 446976;
arr[671409] = 671409;
arr[671490] = 671490;
arr[149782] = 149782;
arr[449676] = 449676;
arr[617728] = 617728;
arr[702189] = 702189;
arr[702918] = 702918;
arr[711099] = 711099;
arr[711909] = 711909;
arr[711990] = 711990;
arr[476892] = 476892;
arr[715959] = 715959;
arr[719199] = 719199;
arr[491688] = 491688;
arr[661288] = 661288;
arr[497682] = 497682;
arr[688000] = 688000;
arr[174028] = 174028;
arr[174082] = 174082;
arr[174208] = 174208;
arr[261378] = 261378;
arr[174280] = 174280;
arr[174298] = 174298;
arr[785295] = 785295;
arr[261783] = 261783;
arr[174802] = 174802;
arr[174820] = 174820;
arr[174982] = 174982;
arr[789750] = 789750;
arr[791289] = 791289;
arr[178294] = 178294;
arr[178942] = 178942;
arr[179428] = 179428;
arr[179482] = 179482;
arr[182974] = 182974;
arr[741928] = 741928;
arr[564912] = 564912;
arr[189742] = 189742;
arr[773896] = 773896;
arr[291375] = 291375;
arr[291753] = 291753;
arr[778936] = 778936;
arr[782896] = 782896;
arr[197428] = 197428;
arr[197482] = 197482;


	arr[MAXN] = 1000255;

	int prev = arr[MAXN];
	for(int i=MAXN-1; i >= 0; i--) {
		if(arr[i] != -1) {
			prev = arr[i];
		} else {
			arr[i] = prev;
		}
	}
}


int main() {
	preprocess();

	int cur;
	while(cin>>cur) {
		if(cur == 0) break;
		cout<<arr[cur]<<endl;
	}
	
	return 0;
}

