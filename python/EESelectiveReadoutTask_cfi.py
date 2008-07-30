import FWCore.ParameterSet.Config as cms

ecalEndcapSelectiveReadoutTask = cms.EDFilter("EESelectiveReadoutTask",
    prefixME = cms.untracked.string('EcalEndcap'),
    enableCleanup = cms.untracked.bool(False),
    mergeRuns = cms.untracked.bool(False),
    EEDigiCollection = cms.InputTag("ecalEBunpacker:eeDigis"),
    EEUsuppressedDigiCollection = cms.InputTag("ecalUnsuppressedDigis"),
    EESRFlagCollection = cms.InputTag("ecalEBunpacker"),
    EcalTrigPrimDigiCollection = cms.InputTag("ecalEBunpacker:EcalTriggerPrimitives"),
    EcalFEDRawCollection = cms.InputTag("source")
)