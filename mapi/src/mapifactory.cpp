#include "mapifactory.h"
#include "default2.h"
#include "refresh_mapi_group.h"



MapiFactory::MapiFactory(Fred *fred)
{
    this->fred = fred;

    try
    {
        this->generateObjects();
    }
    catch (const exception& e)
    {
        Print::PrintError(e.what());
        exit(EXIT_FAILURE);
    }
}

MapiFactory::~MapiFactory()
{
    for (size_t i = 0; i < this->mapiObjects.size(); i++)
    {
        delete this->mapiObjects[i];
    }
    
}

/**
 * 
 * Registering mapi objects into FRED
 * 
**/
void MapiFactory::generateObjects(){
    Default2* vTimeLow = new Default2("VTIME_LOW");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/VTIME_LOW", vTimeLow);
    this->mapiObjects.push_back(vTimeLow);
    Default2* vTimeHigh = new Default2("VTIME_HIGH");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/VTIME_HIGH", vTimeHigh);
    this->mapiObjects.push_back(vTimeHigh);
    Default2* scLevelA = new Default2("SC_LEVEL_A");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/SC_LEVEL_A", scLevelA);
    this->mapiObjects.push_back(scLevelA);
    Default2* scLevelC = new Default2("SC_LEVEL_C");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/SC_LEVEL_C", scLevelC);
    this->mapiObjects.push_back(scLevelC);
    Default2* cLevelA = new Default2("C_LEVEL_A");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/C_LEVEL_A", cLevelA);
    this->mapiObjects.push_back(cLevelA);
    Default2* cLevelC = new Default2("C_LEVEL_C");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/C_LEVEL_C", cLevelC);
    this->mapiObjects.push_back(cLevelC);
    Default2* trigger1Cnt = new Default2("TRIGGER1_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/TRIGGER1_CNT", trigger1Cnt);
    this->mapiObjects.push_back(trigger1Cnt);
    Default2* trigger2Cnt = new Default2("TRIGGER2_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/TRIGGER2_CNT", trigger2Cnt);
    this->mapiObjects.push_back(trigger2Cnt);
    Default2* trigger3Cnt = new Default2("TRIGGER3_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/TRIGGER3_CNT", trigger3Cnt);
    this->mapiObjects.push_back(trigger3Cnt);
    Default2* trigger4Cnt = new Default2("TRIGGER4_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/TRIGGER4_CNT", trigger4Cnt);
    this->mapiObjects.push_back(trigger4Cnt);
    Default2* trigger5Cnt = new Default2("TRIGGER5_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/TRIGGER5_CNT", trigger5Cnt);
    this->mapiObjects.push_back(trigger5Cnt);
    Default2* mainPanel = new Default2("MAIN_PANEL");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/MAIN_PANEL", mainPanel);
    this->mapiObjects.push_back(mainPanel);
    Default2* delayLaser = new Default2("LASER_DELAY");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/LASER_DELAY", delayLaser);
    this->mapiObjects.push_back(delayLaser);
    Default2* sideAStatus = new Default2("SIDE_A_STATUS");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/SIDE_A_STATUS", sideAStatus);
    this->mapiObjects.push_back(sideAStatus);
    Default2* sideCStatus = new Default2("SIDE_C_STATUS");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/SIDE_C_STATUS", sideCStatus);
    this->mapiObjects.push_back(sideCStatus);
    Default2* bkgrnd0Cnt = new Default2("BKGRND0_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/BKGRND0_CNT", bkgrnd0Cnt);
    this->mapiObjects.push_back(bkgrnd0Cnt);
    Default2* bkgrnd1Cnt = new Default2("BKGRND1_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/BKGRND1_CNT", bkgrnd1Cnt);
    this->mapiObjects.push_back(bkgrnd1Cnt);
    Default2* bkgrnd2Cnt = new Default2("BKGRND2_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/BKGRND2_CNT", bkgrnd2Cnt);
    this->mapiObjects.push_back(bkgrnd2Cnt);
    Default2* bkgrnd3Cnt = new Default2("BKGRND3_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/BKGRND3_CNT", bkgrnd3Cnt);
    this->mapiObjects.push_back(bkgrnd3Cnt);
    Default2* bkgrnd4Cnt = new Default2("BKGRND4_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/BKGRND4_CNT", bkgrnd4Cnt);
    this->mapiObjects.push_back(bkgrnd4Cnt);
    Default2* bkgrnd5Cnt = new Default2("BKGRND5_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/BKGRND5_CNT", bkgrnd5Cnt);
    this->mapiObjects.push_back(bkgrnd5Cnt);
    Default2* bkgrnd6Cnt = new Default2("BKGRND6_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/BKGRND6_CNT", bkgrnd6Cnt);
    this->mapiObjects.push_back(bkgrnd6Cnt);
    Default2* bkgrnd7Cnt = new Default2("BKGRND7_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/BKGRND7_CNT", bkgrnd7Cnt);
    this->mapiObjects.push_back(bkgrnd7Cnt);
    Default2* bkgrnd8Cnt = new Default2("BKGRND8_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/BKGRND8_CNT", bkgrnd8Cnt);
    this->mapiObjects.push_back(bkgrnd8Cnt);
    Default2* bkgrnd9Cnt = new Default2("BKGRND9_CNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/BKGRND9_CNT", bkgrnd9Cnt);
    this->mapiObjects.push_back(bkgrnd9Cnt);
    Default2* fpgaTemp = new Default2("FPGA_TEMP");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/FPGA_TEMP", fpgaTemp);
    this->mapiObjects.push_back(fpgaTemp);
    Default2* vPower1 = new Default2("1VPOWER");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/1VPOWER", vPower1);
    this->mapiObjects.push_back(vPower1);
    Default2* vPower18 = new Default2("18VPOWER");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/18VPOWER", vPower18);
    this->mapiObjects.push_back(vPower18);
    Default2* modeSettings = new Default2("MODE_SETTINGS");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/MODE_SETTINGS", modeSettings);
    this->mapiObjects.push_back(modeSettings);
    Default2* laserDivider = new Default2("LASER_DIVIDER");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/LASER_DIVIDER", laserDivider);
    this->mapiObjects.push_back(laserDivider);
    Default2* extSwitches = new Default2("EXT_SW");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/EXT_SW", extSwitches);
    this->mapiObjects.push_back(extSwitches);
    Default2* attenuator = new Default2("ATTENUATOR");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/ATTENUATOR", attenuator);
    this->mapiObjects.push_back(attenuator);
    Default2* triggerModes = new Default2("TRIGGER_MODES");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/TRIGGER_MODES", triggerModes);
    this->mapiObjects.push_back(triggerModes);
    Default2* dsTriggerMask = new Default2("DS_TRIGGER_MASK");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/DS_TRIGGER_MASK", dsTriggerMask);
    this->mapiObjects.push_back(dsTriggerMask);
    Default2* bcidOffset = new Default2("BCID_OFFSET");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/BCID_OFFSET", bcidOffset);
    this->mapiObjects.push_back(bcidOffset);
    Default2* dgTriggerMask = new Default2("DG_TRIGGER_MASK");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/DG_TRIGGER_MASK", dgTriggerMask);
    this->mapiObjects.push_back(dgTriggerMask);
    Default2* systemId = new Default2("SYSTEM_ID");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/SYSTEM_ID", systemId);
    this->mapiObjects.push_back(systemId);
    Default2* cruOrbit = new Default2("CRU_ORBIT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/CRU_ORBIT", cruOrbit);
    this->mapiObjects.push_back(cruOrbit);
    Default2* cruBcFifos = new Default2("CRU_BC");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/CRU_BC", cruBcFifos);
    this->mapiObjects.push_back(cruBcFifos);
    Default2* fifoCount = new Default2("FIFO_COUNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/FIFO_COUNT", fifoCount);
    this->mapiObjects.push_back(fifoCount);
    Default2* selFirstHitDroppedOrbit = new Default2("SEL_FIRST_HIT_DROPPED_ORBIT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/SEL_FIRST_HIT_DROPPED_ORBIT", selFirstHitDroppedOrbit);
    this->mapiObjects.push_back(selFirstHitDroppedOrbit);
    Default2* selLastHitDroppedOrbit = new Default2("SEL_LAST_HIT_DROPPED_ORBIT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/SEL_LAST_HIT_DROPPED_ORBIT", selLastHitDroppedOrbit);
    this->mapiObjects.push_back(selLastHitDroppedOrbit);
    Default2* selHitsDropped = new Default2("SEL_HITS_DROPPED");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/SEL_HITS_DROPPED", selHitsDropped);
    this->mapiObjects.push_back(selHitsDropped);
    Default2* readoutRate = new Default2("READOUT_RATE");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/READOUT_RATE", readoutRate);
    this->mapiObjects.push_back(readoutRate);
    Default2* IPbusFIFOdata = new Default2("IPbus_FIFO_DATA");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/IPbus_FIFO_DATA", IPbusFIFOdata);
    this->mapiObjects.push_back(IPbusFIFOdata);
    Default2* eventsCount = new Default2("EVENTS_COUNT");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/EVENTS_COUNT", eventsCount);
    this->mapiObjects.push_back(eventsCount);
    Default2* mcodeTime = new Default2("MCODE_TIME");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/MCODE_TIME", mcodeTime);
    this->mapiObjects.push_back(mcodeTime);
    Default2* fwTime = new Default2("FW_TIME");
    this->fred->registerMapiObject("FIT_FRED/READOUTCARDS/FIT0/FW_TIME", fwTime);
    this->mapiObjects.push_back(fwTime);
    RefreshMapiGroup *refreshMapiGroup = new RefreshMapiGroup(this->fred);
    this->fred->registerMapiObject(fred->Name() + "/READOUTCARDS/FIT0/REFRESH_MAPI_GROUP",refreshMapiGroup);
    this->mapiObjects.push_back(refreshMapiGroup);


}


