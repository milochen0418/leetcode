class Solution {
    //https://leetcode.com/problems/subarray-sum-equals-k
/* testcase
[1,1,1]
2
[1,2,3]
3
[-962,986,813,664,421,511,38,-332,784,734,-883,-56,552,199,-565,-502,197,868,459,857,776,148,-896,-940,-661,-90,229,-329,437,810,789,828,900,232,418,-571,458,-953,170,552,695,247,802,391,-37,-335,-564,290,460,-52,832,365,850,955,613,-341,-236,-998,184,-391,-15,-236,-224,-1,403,947,247,610,289,-546,-390,-363,324,-396,710,-310,-696,675,705,870,-997,-163,-201,294,-992,902,468,-186,-529,-303,-363,-961,708,246,-872,763,-583,478,368,572,-769,-839,-225,-630,-720,-870,934,-444,-231,395,848,251,301,-127,281,434,630,43,262,-42,-907,64,-69,-128,-477,30,-93,574,-909,-194,-680,696,-418,614,-328,-875,881,-254,-460,-683,117,845,710,600,894,553,-978,-858,894,655,78,-570,-610,-118,366,935,97,-77,868,-765,334,-4,872,-111,111,-176,100,-927,626,-812,-232,943,-936,786,852,617,-155,211,75,-324,-116,-903,432,-457,-415,79,-115,-454,970,-420,244,-595,794,-251,732,-535,745,914,502,570,856,-301,247,492,-692,575,-296,312,817,449,-776,34,894,470,-21,-414,-302,182,-540,408,345,598,-688,177,43,867,78,-644,143,-987,595,297,-344,632,707,-925,752,-593,85,39,-101,120,-899,865,-210,-94,915,-234,783,-451,-964,311,-714,280,744,333,677,937,-313,859,325,835,541,519,802,-660,807,-339,471,-521,-297,-172,-404,985,561,570,-302,484,13,-405,219,285,126,148,689,474,634,979,-809,-855,-641,-665,199,387,-461,247,101,-139,-162,33,538,539,-412,-874,-580,-75,-893,862,782,-639,943,-100,-742,985,-570,998,537,748,181,-121,-652,-483,-510,548,-404,-664,226,244,126,90,913,-759,-913,573,646,537,-743,886,30,-71,649,710,-921,480,-607,-218,781,-366,774,352,259,691,-86,-333,-440,18,-8,947,168,-256,469,-354,-764,-562,79,865,-8,-510,-392,619,962,-860,-633,278,-677,73,-775,529,-373,-186,-285,-611,-290,-938,205,-485,-718,537,-57,-124,-485,984,7,444,-229,-974,317,244,-871,-749,-567,-756,-674,-507,-705,936,862,-661,393,-6,-440,781,379,289,770,790,736,-304,-401,-995,-343,134,607,-598,929,-721,-117,352,-450,-663,891,262,-471,737,-236,-166,-497,5,408,-116,-221,0,657,-808,16,633,786,319,-926,-761,126,-842,-751,227,449,461,845,135,632,-152,-106,-833,-842,-600,-839,-268,586,449,961,-612,726,762,181,-413,-398,-990,-42,-551,378,993,771,-92,-724,739,-882,36,773,-758,-21,-198,5,598,-245,904,-508,156,-73,-221,677,-755,917,-612,-533,-945,524,183,507,362,945,-921,-291,-493,366,-519,773,777,481,920,-15,-670,-805,-146,128,744,276,635,-785,-550,-624,-614,578,249,-325,-329,-476,-294,-945,-962,718,-678,-859,-501,-563,-105,-64,331,-950,-835,-764,-159,383,301,-314,472,648,-769,975,-508,-768,812,757,-537,-723,566,447,532,396,-350,-39,-635,589,-869,301,575,393,346,-51,-2,535,405,551,544,-417,-947,-649,-736,737,95,-28,695,-493,-662,-453,-498,145,264,633,688,-101,414,-923,-659,-384,891,840,-419,143,-227,-384,-257,753,920,-148,-882,-276,958,-516,10,-382,78,-176,127,-156,-227,9,-729,-977,-446,565,-613,-505,-215,346,916,-853,-433,598,-924,463,-797,990,866,-280,16,-313,676,-957,5,931,918,407,-543,-935,281,756,-289,185,-901,-900,16,-452,-756,849,-82,529,295,19,985,-388,-552,612,-618,-336,524,-864,266,70,955,904,-905,-163,-606,744,562,-775,56,-386,517,227,-678,847,-696,448,186,-568,-734,657,167,-342,-150,213,-358,-653,896,269,918,191,-114,633,-841,903,-434,-226,-738,634,-630,-298,832,-92,-318,-778,116,-436,-880,-459,233,734,-988,-826,-477,-366,965,-633,-605,-334,-168,354,-444,526,289,-803,-313,854,573,-765,-878,-5,707,-180,-61,-379,-419,187,729,-740,21,894,-975,-98,-288,-488,-732,-37,529,-672,-433,610,-366,-680,-598,-418,-400,269,-531,53,-705,-201,275,352,77,-75,268,57,-754,-404,-570,-617,-671,378,634,6,-407,-681,933,-276,-130,-468,153,271,565,-621,18,-485,755,521,-805,697,-892,-575,585,-90,-503,85,-685,741,107,-477,314,837,647,-984,-702,-613,-336,-66,-432,161,413,-465,-503,458,412,60,695,907,-957,-777,-654,-907,645,112,4,-25,-559,-751,-289,116,144,-27,628,612,500,-730,-485,270,-485,-558,482,272,-130,-968,215,-648,626,967,-533,321,-335,984,-987,971,-247,-711,857,-20,160,624,-777,-501,923,736,263,427,669,721,-3,-606,-852,32,543,385,523,-468,-608,-406,583,-51,835,-149,330,-506,71,-378,-270,570,644,553,700,-36,44,344,-367,-227,130,-584,269,432,-650,-418,575,693,-989,-693,-942,452,-474,252,-965,251,514,260,526,887,514,249,-54,432,-449,-673,-328,-396,5,231,-654,-941,536,-772,-307,107,-325,671,-111,456,-851,-630,-112,711,-21,-125,462,-559,-865,228,922,258,-565,82,-780,-568,760,558,-973,895,435,258,958,604,628,-995,-14,-986,933,587,-496,835,924,545,574,882,39,-724,596,-929,56,-987,-829,810,0,-149,-679,-436,-521,814,591,-138,995,-683,379,230,259,706,-787,-930,199,-258,777,-511,-760,970,-521,-496,936,-953,894,512,945,158,-417,965,110,-256,194,-494,871,611,-158,609,643,83,131,-131,163,-655,-778,941,-560,759,-878,215,272,-41,-213,-793,774,-999,-880,889,-186,574,-871,-660,-391,129,142,134,-706,-460,-316,488,-895,414,-624,6,-875,-619,898,-159,315,361,544,-881,-587,-530,125,369,-927,-166,-315,-662,88,-703,-996,654,-32,387,604,-384,663,932,427,-667,464,-128,123,712,-199,123,-951,111,44,-871,119,107,-25,-77,265,373,70,886,-92,-475,927,-820,731,479,-758,117,-953,-654,-949,-328,-971,-158,-713,686,956,-462,-762,273,-501,-501,-113,-411,-11,840,296,-243,631,235,-448,228,-188,-328,478,706,357,-438,-46,-914,346,-732,814,966,845,290,-275,398,-621,228,440,47,778,-4,271,-929,-505,359,-434,114,845,707,-410,-16,581,986,-567,-440,315,666,61,394,484,-794,809,404,-446,-736,768,280,544,305,-771,-733,-623,-925,-542,-373,265,-131,34,-743,-427,930,87,-870,275,355,577,-802,538,-285,585,492,469,-379,204,866,-207,919,-994,-721,860,-280,-617,-711,-149,105,-516,-276,-132,390,-43,-501,-69,-15,56,-525,243,-673,-635,-95,-402,448,-541,471,-276,-114,-573,482,395,-94,-123,300,-172,-859,-357,-714,-674,-53,791,-424,-479,186,657,-728,952,447,471,-379,855,170,504,431,-872,-807,156,110,-66,653,482,632,292,226,480,-731,-270,-211,-407,729,-954,-234,165,-139,-279,328,-386,-306,-264,-808,663,-762,-823,-106,362,-963,884,-685,893,-969,997,912,-925,271,-581,139,711,-33,-122,5,-452,295,489,371,-177,975,-794,411,946,-291,-848,-801,-5,-568,-965,-545,-84,152,-338,-437,-595,-531,504,73,-383,309,-425,-580,16,-778,-715,-808,-280,-228,840,362,-590,-48,129,879,132,-61,672,-828,369,274,867,-118,482,-5,655,305,703,799,-361,931,-800,170,252,733,786,-687,-533,-781,475,-731,-309,550,344,-833,729,232,885,728,-343,861,-704,895,-647,248,787,557,884,261,424,-186,-461,-192,95,650,-343,-682,-106,679,277,624,-490,40,-644,-393,24,-566,-644,-530,-136,411,-449,772,-139,881,660,876,795,646,852,891,404,-390,-568,-406,-161,757,165,541,550,-224,-748,-559,-757,-94,-756,550,-871,-432,275,-158,-318,641,-529,-807,609,50,744,-566,-732,907,-341,-127,-44,119,456,403,-430,959,806,-769,731,-938,359,753,-53,-253,915,-703,-246,-548,845,-891,703,-750,78,939,311,82,-128,-522,-256,-281,58,-552,-719,132,986,589,501,52,788,-685,107,-381,-724,43,439,126,368,-605,-233,-594,-996,41,-740,588,-739,431,-342,-575,574,-151,578,-110,860,738,-446,69,992,326,113,613,828,162,-177,-786,-760,76,-403,-23,970,446,599,865,-367,-153,-810,981,-84,395,69,633,-48,524,-135,12,-803,-629,-643,-298,-735,666,850,-366,570,635,-513,-347,-55,-706,-998,-809,-754,-625,588,613,478,-484,814,821,183,67,-340,331,809,-271,505,-916,-632,33,583,322,630,-460,-657,-606,776,-690,946,102,-171,699,-514,958,453,901,-83,-326,684,-188,742,-842,818,-604,736,-61,-105,-998,393,486,-852,-135,328,784,-583,666,931,-889,-467,-437,-691,286,635,-940,478,-583,744,886,-271,691,72,-337,678,259,182,-165,-725,366,-514,69,641,70,-969,271,-120,754,625,-232,-980,-901,-64,-983,71,-343,222,-284,834,619,-273,-744,-104,-33,411,-89,-945,780,321,-336,886,264,310,976,-640,-682,-439,54,-275,-370,661,198,303,-607,714,931,-328,681,-781,-337,-513,-89,334,-817,-941,-507,-41,-213,90,-935,-285,-566,410,694,-771,-391,790,-372,154,823,88,576,740,595,79,570,-116,-530,-422,799,168,-865,-884,583,508,-403,-83,-995,528,-869,-157,-10,394,176,-726,86,-446,-353,-808,-173,-427,-686,120,734,-600,115,439,595,-225,734,-941,371,-124,-257,-59,-162,-396,-625,486,-38,-673,-892,89,147,927,872,770,521,-648,-279,28,-990,-470,183,777,-279,144,212,58,-442,-489,-133,-522,871,634,1,-253,-992,139,-995,-855,579,-741,-638,385,264,406,-340,-551,-461,-194,122,-342,365,633,211,-445,112,508,689,320,131,-700,724,-127,-586,600,344,-587,246,-626,-133,333,-535,531,-678,829,995,-956,787,126,909,143,152,-216,-525,600,-136,664,-320,-619,714,560,-990,915,-238,917,364,933,-336,-859,381,614,609,-502,-658,600,642,-424,56,248,595,295,-424,849,519,376,-351,937,-783,396,287,241,-185,979,-31,-484,-905,447,-306,-824,-590,-378,777,533,349,127,-45,658,814,682,908,-159,383,215,-906,549,-398,-366,-270,-761,228,395,-704,-723,-258,243,961,-230,502,-460,-445,101,-496,69,664,982,-134,277,140,-370,-113,-603,-233,-45,-406,-845,81,134,-927,-80,1,937,-1,442,-889,-522,571,-507,267,931,-252,-768,721,-263,-572,26,-81,653,-268,283,441,-60,983,-888,-965,376,-795,-295,444,952,-889,578,971,327,-370,-39,915,-197,-943,605,744,427,113,-155,681,-900]
998
*/    
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        //nums = [1,1,1], k=2
        vector<long> L(n);//L[i] = sum of nums[0..i]
        for(int i=0;i<n;i++)
            L[i] = (i==0) ? nums[i] : L[i-1]+nums[i];
        //L = [1,2,3]
        vector<long> R(n);//R[i] = sum of nums[i..n-1]
        for(int i=n-1;i>=0;i--)
            R[i] = (i==n-1) ? nums[i] : R[i+1]+nums[i];
        //R = [3,2,1]
        int total_n = accumulate(nums.begin(), nums.end(), 0);
        long total = (long) total_n;
        //So for all i>=j, L[i] + R[j] - total = sum of nums[i..j]. 
        //total = 3
        
        
        unordered_map<long,set<int>> mp; 
        //https://www.geeksforgeeks.org/stddistance-in-c/
        //https://blog.csdn.net/henu_student/article/details/104419645
        for(int j=0; j<n ; j++) {
            mp[R[j]].insert(j);
        }
        for(int i=0; i<n; i++) {
            //cnt += mp[-1*(L[i]-total)].size();
            
            auto& s=mp[-1*(L[i]-total)];
            cnt += distance(s.begin(), s.lower_bound(i));
        }
        return cnt;
            
        for(int j=0; j<n; j++) {
            for(int i=j;i<n;i++) {
                int sum = L[i] + R[j] - total;
                if(sum == k) cnt++;
            }
        }
    
        return cnt;   
    }
};