import FWCore.ParameterSet.Config as cms

ecalEndcapClusterTask = cms.EDFilter("EEClusterTask",
    prefixME = cms.untracked.string('EcalEndcap'),
    enableCleanup = cms.untracked.bool(False),
    mergeRuns = cms.untracked.bool(False),    
    EcalRawDataCollection = cms.InputTag("ecalEBunpacker"),
    BasicClusterCollection = cms.InputTag("multi5x5BasicClusters","multi5x5EndcapBasicClusters"),
    SuperClusterCollection = cms.InputTag("multi5x5SuperClusters","multi5x5EndcapSuperClusters"),
    reducedEndcapRecHitCollection = cms.InputTag("ecalRecHit","EcalRecHitsEE")
)

