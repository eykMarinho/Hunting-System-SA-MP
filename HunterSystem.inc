/*

            ooo        ooooo       .o.       ooooooooo.   ooooo ooooo      ooo ooooo   ooooo   .oooooo.   
            `88.       .888'      .888.      `888   `Y88. `888' `888b.     `8' `888'   `888'  d8P'  `Y8b  
            888b     d'888      .8"888.      888   .d88'  888   8 `88b.    8   888     888  888      888 
            8 Y88. .P  888     .8' `888.     888ooo88P'   888   8   `88b.  8   888ooooo888  888      888 
            8  `888'   888    .88ooo8888.    888`88b.     888   8     `88b.8   888     888  888      888 
            8    Y     888   .8'     `888.   888  `88b.   888   8       `888   888     888  `88b    d88' 
            o8o        o888o o88o     o8888o o888o  o888o o888o o8o        `8  o888o   o888o  `Y8bood8P'  

*/

            // Includes
#include <a_samp>
#include <streamer>
#include <Pawn.CMD>
#include <YSI_Coding\y_hooks>
#include <YSI_Data\y_iterate>

            //Defines
#define     E_HUNTER_ANIMAL_COUNT 168

            //defines [Fake]
static const E_HUNTER_MODEL_ANIMAL = 19315;
static const E_HUNTER_ANIMAL_TIMER = 20; // 20 Segundos
static const E_HUNTER_PRICE_MEAT = 50;  //Valor Unidade

            // Forwards
forward PlayerEsfolando(playerid);

enum ANIMAL_POSITIONS {
    Float:E_ANIMAL_POSX,
    Float:E_ANIMAL_POSY,
    Float:E_ANIMAL_POSZ
}
static const Float:E_HUNTER_ANIMAL_POS[E_HUNTER_ANIMAL_COUNT][ANIMAL_POSITIONS] = {
    {-1921.008789, -2361.988281, 30.071756},
    {-1933.591796, -2348.596435, 32.830333},
    {-1952.499511, -2315.275634, 39.441543},
    {-1919.660766, -2286.318115, 53.055145},
    {-1922.356201, -2256.736328, 63.453571},
    {-1880.180908, -2230.252441, 74.520889},
    {-1835.273681, -2240.145996, 71.546615},
    {-1830.029663, -2223.691406, 76.039657},
    {-1810.471801, -2219.106201, 75.087791},
    {-1800.243041, -2238.759277, 69.939285},
    {-1784.742309, -2251.994873, 64.692077},
    {-1766.237915, -2269.364257, 57.113063},
    {-1742.799438, -2275.777343, 51.290222},
    {-1738.739501, -2252.577392, 54.957786},
    {-1723.482666, -2220.040283, 52.656852},
    {-1732.650634, -2192.513183, 56.274665},
    {-1725.407226, -2161.026367, 52.952571},
    {-1720.180297, -2140.259277, 52.482482},
    {-1713.305664, -2144.619628, 51.122558},
    {-1733.071044, -2135.375732, 51.295150},
    {-1731.156982, -2121.432128, 49.120895},
    {-1748.667724, -2116.812744, 49.932498},
    {-1774.552734, -2118.770263, 54.445812},
    {-1784.230102, -2147.096191, 64.959831},
    {-1810.176635, -2147.218750, 69.292846},
    {-1834.589111, -2151.159423, 74.415061},
    {-1829.313354, -2175.934570, 79.567649},
    {-1809.322387, -2183.652832, 76.866607},
    {-1780.416870, -2202.985351, 72.108665},
    {-1871.765502, -2173.228027, 84.335533},
    {-1914.931030, -2155.732666, 79.110168},
    {-1936.554443, -2145.505371, 77.530426},
    {-1958.232788, -2135.793212, 76.038269},
    {-1964.058837, -2115.235839, 77.725067},
    {-1991.415405, -2096.339111, 75.502136},
    {-2009.635620, -2118.758056, 68.712028},
    {-2050.157958, -2116.108154, 58.076969},
    {-2016.784790, -2056.193847, 75.724372},
    {-1993.869628, -2023.614257, 83.034713},
    {-2000.529174, -1971.133422, 81.858818},
    {-2026.622680, -1981.701049, 80.242553},
    {-2022.915161, -2006.448852, 80.951362},
    {-1988.505615, -2037.484008, 80.227455},
    {-1918.875122, -2020.733154, 75.573921},
    {-1879.395263, -2043.720581, 68.675872},
    {-1846.546997, -2048.355957, 67.079223},
    {-1823.983764, -2036.233642, 71.273880},
    {-1827.230224, -1985.339233, 87.041625},
    {-1837.248535, -1962.257080, 89.596725},
    {-1827.445068, -1942.417602, 91.503532},
    {-1790.921875, -1942.326416, 95.318038},
    {-1746.779907, -1980.665649, 91.269416},
    {-1716.561645, -1977.210205, 95.164802},
    {-1691.960937, -1971.887451, 102.114021},
    {-1682.478393, -1968.608642, 101.707962},
    {-1676.317016, -1955.103515, 102.525016},
    {-1660.834960, -1936.310913, 100.707054},
    {-1628.421752, -1872.344360, 88.756668},
    {-1627.106811, -1858.155761, 84.109649},
    {-1619.240844, -1835.878417, 75.326370},
    {-1605.844604, -1842.833618, 75.808471},
    {-1586.582885, -1852.743896, 78.532218},
    {-1562.123291, -1854.022949, 76.582733},
    {-1545.889160, -1809.940551, 62.347942},
    {-1542.599243, -1787.781494, 55.850002},
    {-1482.535278, -1834.118041, 63.117385},
    {-1484.313354, -1852.739868, 66.229644},
    {-1493.952636, -1868.315063, 70.726013},
    {-1494.884277, -1876.336914, 71.314849},
    {-1494.299072, -1880.003295, 71.294601},
    {-1498.960327, -1881.626586, 72.612182},
    {-1504.909912, -1914.569702, 72.896697},
    {-1539.176147, -1941.818603, 81.060989},
    {-1600.210693, -1946.489990, 97.226036},
    {-1607.911621, -1962.392333, 93.307899},
    {-1595.520263, -1976.738525, 87.754577},
    {-1677.272216, -1988.262084, 92.950698},
    {-1629.323242, -2009.074462, 79.269630},
    {-1601.058471, -2033.101928, 66.764785},
    {-1573.605102, -2038.155273, 61.895214},
    {-1568.685058, -2064.077880, 49.699661},
    {-1550.979492, -2075.010498, 42.216060},
    {-1569.654296, -2091.542968, 37.729831},
    {-1591.030395, -2090.104003, 41.420906},
    {-1618.506835, -2089.943847, 43.078983},
    {-1637.977416, -2072.703369, 49.390560},
    {-1651.261718, -2087.852783, 42.915779},
    {-1642.213256, -2106.623535, 37.533035},
    {-1654.656372, -2104.020263, 39.047233},
    {-1677.514038, -2081.039794, 41.760009},
    {-1697.181274, -2068.620361, 42.683101},
    {-1713.039062, -2069.249511, 43.920104},
    {-1734.139404, -2014.925781, 76.011497},
    {-1762.863037, -1998.606079, 83.485473},
    {-1806.696411, -2009.736572, 80.306465},
    {-1847.746337, -2033.144531, 72.364379},
    {-1868.437744, -2018.218261, 77.554000},
    {-1879.395874, -2007.563598, 80.529251},
    {-1895.411499, -2022.837158, 76.634811},
    {-1877.913208, -2031.820800, 72.785331},
    {-1879.494384, -2038.292846, 70.535659},
    {-1918.334106, -2046.851562, 66.877822},
    {-1894.797607, -2066.115966, 61.929046},
    {-1805.057983, -2120.162353, 57.670059},
    {-1748.464721, -2136.625976, 54.136474},
    {-1636.419921, -2271.620849, 35.420497},
    {-1603.260864, -2218.864746, 24.085659},
    {-1612.898315, -2187.682128, 24.987581},
    {-1572.933227, -2187.175781, 14.362590},
    {-1543.016845, -2177.083496, 6.830154},
    {-1526.724365, -2169.477294, 3.024921},
    {-1539.962646, -2190.411621, 4.489025},
    {-1563.703613, -2227.351318, 10.221519},
    {-1588.206054, -2260.559082, 22.712379},
    {-1642.285278, -2299.781494, 61.148384},
    {-1607.029907, -2363.424804, 44.453933},
    {-1606.505981, -2395.460205, 45.335105},
    {-1588.227783, -2412.553955, 46.155715},
    {-1552.516845, -2444.225097, 47.237266},
    {-1534.755737, -2456.117187, 48.531505},
    {-1496.172729, -2486.654296, 58.858261},
    {-1461.741577, -2488.456542, 52.142208},
    {-1457.252319, -2493.884765, 53.191913},
    {-1415.936157, -2491.395996, 48.131671},
    {-1428.628906, -2470.678466, 43.511459},
    {-1414.924438, -2461.877929, 41.253631},
    {-1397.356079, -2445.785644, 37.157077},
    {-1386.118774, -2434.743164, 35.121047},
    {-1364.474609, -2435.560302, 32.706607},
    {-1325.365600, -2448.115478, 27.291259},
    {-1317.162597, -2490.215087, 26.123615},
    {-1338.820556, -2567.215576, 41.836669},
    {-1455.213134, -2427.900390, 31.035980},
    {-1472.412963, -2380.916992, 18.205364},
    {-1477.985717, -2365.929199, 15.808469},
    {-1482.361694, -2363.345947, 15.303401},
    {-1489.893676, -2365.569335, 15.433956},
    {-1494.481689, -2361.694335, 14.729530},
    {-1503.673706, -2349.594238, 8.968833},
    {-1494.877929, -2343.885498, 7.278419},
    {-1480.803710, -2339.199218, 9.410255},
    {-1469.576904, -2341.428466, 13.623069},
    {-1453.950683, -2348.847656, 16.890710},
    {-1413.564819, -2347.332031, 29.519535},
    {-1394.300415, -2301.493896, 36.189918},
    {-1383.436279, -2286.513427, 38.992088},
    {-1377.566406, -2255.308593, 36.794975},
    {-1393.466430, -2236.454589, 33.449031},
    {-1398.008544, -2210.750976, 27.188856},
    {-1402.974121, -2185.323730, 21.519025},
    {-1391.565917, -2190.022705, 22.735475},
    {-1372.921142, -2204.051269, 25.742223},
    {-1365.963256, -2143.618164, 26.528715},
    {-1375.021240, -2130.837402, 27.608497},
    {-1392.408203, -2129.355224, 24.390003},
    {-1399.350952, -2133.143798, 22.535701},
    {-1376.422851, -2108.536621, 28.932649},
    {-1353.989501, -2097.108642, 28.199979},
    {-1340.473632, -2088.139648, 26.372823},
    {-1481.983276, -2174.642089, 2.137424},
    {-1482.740234, -2189.645263, 4.713485},
    {-1482.993164, -2207.746582, 7.090320},
    {-1465.649414, -2217.490722, 13.038906},
    {-1441.655883, -2202.660888, 16.796588},
    {-1413.221069, -2198.304443, 22.448322},
    {-1405.444335, -2194.713134, 23.437698},
    {-1489.007812, -2141.236572, 2.433990},
    {-1508.469238, -2142.087158, 1.413806}
};

enum {
    HUNTER_STATE_LIFE = 0,
    HUNTER_STATE_DEATH = 1,
    HUNTER_STATE_OPEN = 2
}

enum PLAYER_HUNTER_DATA {
    E_HUNTER_STATE,
    E_HUNTER_ANIMAL,
    E_HUNTER_OBJECT,
    E_HUNTER_CP,
    E_HUNTER_TIMER
}
static
    Iterator:AnimalDisponible<E_HUNTER_ANIMAL_COUNT>,
    e_PlayerHunter[MAX_PLAYERS][PLAYER_HUNTER_DATA],
    e_PlayerMeat[MAX_PLAYERS];



hook OnPlayerConnect(playerid) {

    e_PlayerHunter[playerid][E_HUNTER_ANIMAL] = -1;
    e_PlayerMeat[playerid] = 0;
    return Y_HOOKS_CONTINUE_RETURN_1;
}
hook OnPlayerDisconnect(playerid, reason)
{
    DestroyAnimal(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}
hook OnPlayerShootDynamicObj(playerid, weaponid, objectid, Float:x, Float:y, Float:z) {

    if(objectid == e_PlayerHunter[playerid][E_HUNTER_OBJECT]) {

        if(e_PlayerHunter[playerid][E_HUNTER_STATE] == HUNTER_STATE_LIFE) {

            new 
                Float:X, 
                Float:Y, 
                Float:Z;

		    GetDynamicObjectPos(objectid, X, Y, Z);
		    MoveDynamicObject(objectid, X, Y, Z-0.3, 0.7, 90.0000, 0.0000, 0.0000);

            e_PlayerHunter[playerid][E_HUNTER_STATE] = HUNTER_STATE_DEATH;
            e_PlayerHunter[playerid][E_HUNTER_CP] = CreateDynamicCP(X, Y, Z, 1.0, 0, 0, playerid, 10.0);

            SendClientMessage(playerid, 0x1f883dFF, "CACADOR: Excelente tiro! Voce abateu o animal com sucesso!");
            SendClientMessage(playerid, 0xffea00FF, "[INFO]: {ffffff}Aproxime-se do animal para coletar seus recursos!");
        }
        return Y_HOOKS_BREAK_RETURN_1;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}
hook OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP:checkpointid) {

    if(checkpointid == e_PlayerHunter[playerid][E_HUNTER_CP]) {

        e_PlayerHunter[playerid][E_HUNTER_TIMER] = SetTimerEx("PlayerEsfolando", (E_HUNTER_ANIMAL_TIMER * 1000), false, "i", playerid);

        SetPlayerAttachedObject(playerid, 9, 335, 6, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);
        ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_LOOP", 4.1, 1, 0, 0, 0, 0, 1);

        DestroyDynamicCP(e_PlayerHunter[playerid][E_HUNTER_CP]);
        e_PlayerHunter[playerid][E_HUNTER_STATE] = HUNTER_STATE_OPEN;

        SendClientMessage(playerid, 0x1f883dFF, "CACADOR: Voce esta coletando os recursos do animal!");
        return Y_HOOKS_BREAK_RETURN_1;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}
/*

                    ooooooooo.   ooooo     ooo oooooooooo.  ooooo        ooooo   .oooooo.   
                    `888   `Y88. `888'     `8' `888'   `Y8b `888'        `888'  d8P'  `Y8b  
                    888   .d88'  888       8   888     888  888          888  888          
                    888ooo88P'   888       8   888oooo888'  888          888  888          
                    888          888       8   888    `88b  888          888  888          
                    888          `88.    .8'   888    .88P  888       o  888  `88b    ooo  
                    o888o           `YbodP'    o888bood8P'  o888ooooood8 o888o  `Y8bood8P'  

*/
public PlayerEsfolando(playerid) {
    ClearAnimations(playerid, 1);
    RemovePlayerAttachedObject(playerid, 9);

    if(DestroyAnimal(playerid)) {
        if(GivePlayerMeat(playerid))
            SendClientMessage(playerid, 0x1f883dFF, "CACADOR: Voce conseguiu coletar os recursos do animal!");
    }
    return 1;
}
/*

                    .oooooo..o ooooooooooooo   .oooooo.     .oooooo.   oooo    oooo  .oooooo..o 
                    d8P'    `Y8 8'   888   `8  d8P'  `Y8b   d8P'  `Y8b  `888   .8P'  d8P'    `Y8 
                    Y88bo.           888      888      888 888           888  d8'    Y88bo.      
                    `"Y8888o.       888      888      888 888           88888[       `"Y8888o.  
                        `"Y88b      888      888      888 888           888`88b.         `"Y88b 
                    oo     .d8P      888      `88b    d88' `88b    ooo   888  `88b.  oo     .d8P 
                    8""88888P'      o888o      `Y8bood8P'   `Y8bood8P'  o888o  o888o 8""88888P'  

*/
static stock DestroyAnimal(playerid)
{
    if(!IsPlayerHunter(playerid)) 
        return false;

    DestroyDynamicObject(STREAMER_TAG_OBJECT:e_PlayerHunter[playerid][E_HUNTER_OBJECT]);
    Iter_Remove(AnimalDisponible, e_PlayerHunter[playerid][E_HUNTER_ANIMAL]);

    if(GetStateAnimal(playerid) == HUNTER_STATE_DEATH)
        DestroyDynamicCP(e_PlayerHunter[playerid][E_HUNTER_CP]);
    
    if(GetStateAnimal(playerid) == HUNTER_STATE_OPEN) 
        KillTimer(e_PlayerHunter[playerid][E_HUNTER_TIMER]);

    static const e_Clear[PLAYER_HUNTER_DATA];
    e_PlayerHunter[playerid] = e_Clear; 

    e_PlayerHunter[playerid][E_HUNTER_ANIMAL] = -1;
    return true;
}

static stock GetStateAnimal(playerid)
    return e_PlayerHunter[playerid][E_HUNTER_STATE];

static stock GetAnimalID(playerid)
    return e_PlayerHunter[playerid][E_HUNTER_ANIMAL];

static stock IsPlayerHunter(playerid)
    return ((e_PlayerHunter[playerid][E_HUNTER_ANIMAL] != -1) ? (true) : (false));

static stock CreateAnimalHunter(playerid) {

    new index = Iter_Free(AnimalDisponible);
    if(index == -1) return -1;   

    Iter_Add(AnimalDisponible, index);

    e_PlayerHunter[playerid][E_HUNTER_ANIMAL] = index;
    e_PlayerHunter[playerid][E_HUNTER_STATE] = HUNTER_STATE_LIFE;
    e_PlayerHunter[playerid][E_HUNTER_OBJECT] = CreateDynamicObject (E_HUNTER_MODEL_ANIMAL, E_HUNTER_ANIMAL_POS[index][E_ANIMAL_POSX], E_HUNTER_ANIMAL_POS[index][E_ANIMAL_POSY], E_HUNTER_ANIMAL_POS[index][E_ANIMAL_POSZ]-0.6, 0.0, 0.0, random(360));
    SetPlayerPos(playerid,E_HUNTER_ANIMAL_POS[index][E_ANIMAL_POSX], E_HUNTER_ANIMAL_POS[index][E_ANIMAL_POSY], E_HUNTER_ANIMAL_POS[index][E_ANIMAL_POSZ] + 2);
    return index;
}
static stock GivePlayerMeat(playerid, Meat = 1) {
    if(!e_PlayerMeat[playerid]) 
        SetPlayerAttachedObject(playerid, 8, 2805, 1, 0.1580, -0.2340, 0.0220, 0.0000, 74.4000, 0.0000, 0.5940, 0.6360, 0.4280, 0, 0);

    e_PlayerMeat[playerid] += Meat;
    return true;
}
static stock GetPlayerMeat(playerid) 
    return e_PlayerMeat[playerid];

/*

                    .oooooo.     .oooooo.   ooo        ooooo       .o.       ooooo      ooo oooooooooo.     .oooooo.    .oooooo..o 
                    d8P'  `Y8b   d8P'  `Y8b  `88.       .888'      .888.      `888b.     `8' `888'   `Y8b   d8P'  `Y8b  d8P'    `Y8 
                    888          888      888  888b     d'888      .8"888.      8 `88b.    8   888      888 888      888 Y88bo.      
                    888          888      888  8 Y88. .P  888     .8' `888.     8   `88b.  8   888      888 888      888  `"Y8888o.  
                    888          888      888  8  `888'   888    .88ooo8888.    8     `88b.8   888      888 888      888      `"Y88b 
                    `88b    ooo  `88b    d88'  8    Y     888   .8'     `888.   8       `888   888     d88' `88b    d88' oo     .d8P 
                    `Y8bood8P'   `Y8bood8P'  o8o        o888o o88o     o8888o o8o        `8  o888bood8P'    `Y8bood8P'  8""88888P'  

*/
CMD:assobiar(playerid) {
    
    if(IsPlayerHunter(playerid))
        return SendClientMessage(playerid, 0xFFFFFFFF, "CACADOR: {ff0000}Um animal ja foi avistado na area!");

    if(CreateAnimalHunter(playerid) != -1) SendClientMessage(playerid, -1, "{14620e}CACADOR: Ao assobiar, voce atraiu a presenca de um animal. Siga-o e consulte o seu mapa para localiza-lo.");
    else SendClientMessage(playerid, -1, "{FF0000}CACADOR: Voce nao conseguiu atrair nenhum animal.");
    return true;
}
CMD:vcarne(playerid) {
    new
        Meat = GetPlayerMeat(playerid);

    if(!Meat)
        return SendClientMessage(playerid, -1, "{FF0000}CACADOR: Voce nao possui nenhuma carne.");
    
    GivePlayerMoney(playerid, (E_HUNTER_PRICE_MEAT * Meat));

    e_PlayerMeat[playerid] = 0;
    RemovePlayerAttachedObject(playerid, 8);

    SendClientMessage(playerid, -1, "{8adc54}CACADOR: Voce vendeu todas suas carnes");
    return true;
}