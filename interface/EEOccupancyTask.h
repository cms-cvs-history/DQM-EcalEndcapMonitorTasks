#ifndef EEOccupancyTask_H
#define EEOccupancyTask_H

/*
 * \file EEOccupancyTask.h
 *
 * $Date: 2008/01/23 07:15:44 $
 * $Revision: 1.11 $
 * \author G. Della Ricca
 *
*/

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

class MonitorElement;
class DaqMonitorBEInterface;

class EEOccupancyTask: public edm::EDAnalyzer{

public:

/// Constructor
EEOccupancyTask(const edm::ParameterSet& ps);

/// Destructor
virtual ~EEOccupancyTask();

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

edm::InputTag EEDigiCollection_;
edm::InputTag EcalPnDiodeDigiCollection_;
edm::InputTag EcalRecHitCollection_;
edm::InputTag EcalTrigPrimDigiCollection_;

MonitorElement* meEvent_[18];
MonitorElement* meOccupancy_[18];
MonitorElement* meOccupancyMem_[18];

MonitorElement* meEEDigiOccupancy_[2], *meEEDigiOccupancyProjX_[2], *meEEDigiOccupancyProjY_[2];
MonitorElement* meEERecHitOccupancy_[2], *meEERecHitOccupancyProjX_[2], *meEERecHitOccupancyProjY_[2];
MonitorElement* meEERecHitOccupancyThr_[2], *meEERecHitOccupancyProjXThr_[2], *meEERecHitOccupancyProjYThr_[2];
MonitorElement* meEETrigPrimDigiOccupancy_[2], *meEETrigPrimDigiOccupancyProjX_[2], *meEETrigPrimDigiOccupancyProjY_[2];
MonitorElement* meEETrigPrimDigiOccupancyThr_[2], *meEETrigPrimDigiOccupancyProjXThr_[2], *meEETrigPrimDigiOccupancyProjYThr_[2];

float recHitEnergyMin_;
float trigPrimEtMin_;

bool init_;

};

#endif
