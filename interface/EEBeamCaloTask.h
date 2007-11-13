#ifndef EEBeamCaloTask_H
#define EEBeamCaloTask_H

/*
 * \file EEBeamCaloTask.h
 *
 * $Date: 2007/11/10 15:33:55 $
 * $Revision: 1.4 $
 * \author A. Ghezzi
 *
*/

#include <string>

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

class MonitorElement;
class DaqMonitorBEInterface;

class EEBeamCaloTask: public edm::EDAnalyzer{

public:

/// Constructor
EEBeamCaloTask(const edm::ParameterSet& ps);

/// Destructor
virtual ~EEBeamCaloTask();

protected:

/// Analyze
void analyze(const edm::Event& e, const edm::EventSetup& c);

/// BeginJob
void beginJob(const edm::EventSetup& c);

/// EndJob
void endJob(void);

/// Setup
void setup(void);

/// Cleanup
void cleanup(void);

private:

int ievt_;

DaqMonitorBEInterface* dbe_;

bool enableCleanup_;

edm::InputTag EcalTBEventHeader_;
edm::InputTag EcalRawDataCollection_;
edm::InputTag EBDigiCollection_;
edm::InputTag EcalUncalibratedRecHitCollection_;

const static int cryInArray_ = 9;
const static int defaultPede_ = 200;

MonitorElement* meBBCaloPulseProf_[cryInArray_];
MonitorElement* meBBCaloPulseProfG12_[cryInArray_];
MonitorElement* meBBCaloGains_[cryInArray_];
MonitorElement* meBBCaloEne_[cryInArray_];

//MonitorElement* meBBCaloPulseProfMoving_[cryInArray_];
//MonitorElement* meBBCaloPulseProfG12Moving_[cryInArray_];
//MonitorElement* meBBCaloGainsMoving_[cryInArray_];
//MonitorElement* meBBCaloEneMoving_[cryInArray_];

MonitorElement* meBBCaloCryRead_;
//MonitorElement* meBBCaloCryReadMoving_;

MonitorElement* meBBCaloAllNeededCry_;
MonitorElement* meBBNumCaloCryRead_;

MonitorElement* meBBCaloE3x3_;
MonitorElement* meBBCaloE3x3Moving_;

/* MonitorElement* meBBCaloE3x3Cry_[1701]; */
/* MonitorElement* meBBCaloE1Cry_[1701]; */

MonitorElement* meBBCaloCryOnBeam_;
MonitorElement* meBBCaloMaxEneCry_;

MonitorElement* TableMoving_;

MonitorElement* CrystalsDone_;

MonitorElement* CrystalInBeam_vs_Event_;

MonitorElement* meEEBCaloReadCryErrors_;

MonitorElement* meEEBCaloE1vsCry_;

MonitorElement* meEEBCaloE3x3vsCry_;

MonitorElement* meEEBCaloEntriesVsCry_;

MonitorElement* meEEBCaloBeamCentered_;

MonitorElement* meEEBCaloE1MaxCry_;

MonitorElement* meEEBCaloDesync_;

bool init_;

bool profileArranged_;

int PreviousTableStatus_[2];
int PreviousCrystalinBeam_[3];

int cib_[12];// used 10
bool changed_tb_status_;
bool changed_cry_in_beam_;
int evt_after_change_ ;
bool  wasFakeChange_;
int lastStableStatus_ ;
int table_step_, crystal_step_;
int event_last_reset_;
int last_cry_in_beam_;
int previous_cry_in_beam_;
int previous_ev_num_;
// 0=stable, 1=moving,
// PreviousTableStatus_[0]-> event=current -2
// PreviousTableStatus_[1]-> event=current -1

//int cryIn3x3_[cryInArray_];

};

#endif
