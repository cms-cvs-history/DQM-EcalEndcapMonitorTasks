import FWCore.ParameterSet.Config as cms

ecalEndcapPedestalOnlineTask = cms.EDFilter("EEPedestalOnlineTask",
    EEDigiCollection = cms.InputTag("ecalEBunpacker","eeDigis"),
    enableCleanup = cms.untracked.bool(True)
)

