#ifndef EEOccupancyTask_H
#define EEOccupancyTask_H

/*
 * \file EEOccupancyTask.h
 *
 * $Date: 2010/08/11 14:21:54 $
 * $Revision: 1.28 $
 * \author G. Della Ricca
 *
*/

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/Framework/interface/ESHandle.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"

#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"

#include "DataFormats/EcalDetId/interface/EEDetId.h"

class MonitorElement;
class DQMStore;

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
void beginJob(void);

/// EndJob
void endJob(void);

/// BeginRun
void beginRun(const edm::Run & r, const edm::EventSetup & c);

/// EndRun
void endRun(const edm::Run & r, const edm::EventSetup & c);

/// Reset
void reset(void);

/// Setup
void setup(void);

/// Cleanup
void cleanup(void);

private:

int ievt_;

DQMStore* dqmStore_;

std::string prefixME_;

bool enableCleanup_;

bool mergeRuns_;

edm::InputTag EcalRawDataCollection_;
edm::InputTag EEDigiCollection_;
edm::InputTag EcalPnDiodeDigiCollection_;
edm::InputTag EcalRecHitCollection_;
edm::InputTag EcalTrigPrimDigiCollection_;

enum runClassification { notdata, physics, testpulse, laser, led, pedestal };

MonitorElement* meEvent_[18];
MonitorElement* meOccupancy_[18];
MonitorElement* meOccupancyMem_[18];

 MonitorElement *meDCCOccupancy_;
MonitorElement* meEEDigiOccupancy_[2];
MonitorElement* meEEDigiOccupancyProEta_[2];
MonitorElement* meEEDigiOccupancyProPhi_[2];
 MonitorElement* meEEDigiNumber_;
 MonitorElement* meEEDigiNumberPerFED_;
MonitorElement* meEERecHitOccupancy_[2];
MonitorElement* meEERecHitOccupancyProEta_[2];
MonitorElement* meEERecHitOccupancyProPhi_[2];
MonitorElement* meEERecHitOccupancyThr_[2];
MonitorElement* meEERecHitOccupancyProEtaThr_[2];
MonitorElement* meEERecHitOccupancyProPhiThr_[2];
MonitorElement* meEERecHitNumber_;
MonitorElement* meEERecHitNumberPerFED_;
MonitorElement* meEETrigPrimDigiOccupancy_[2];
MonitorElement* meEETrigPrimDigiOccupancyProEta_[2];
MonitorElement* meEETrigPrimDigiOccupancyProPhi_[2];
MonitorElement* meEETrigPrimDigiOccupancyThr_[2];
MonitorElement* meEETrigPrimDigiOccupancyProEtaThr_[2];
MonitorElement* meEETrigPrimDigiOccupancyProPhiThr_[2];

float recHitEnergyMin_;
float trigPrimEtMin_;

edm::ESHandle<CaloGeometry> pGeometry_;

float geometryEE[EEDetId::kSizeForDenseIndexing][2];

bool init_;
bool initCaloGeometry_;

};

#endif
