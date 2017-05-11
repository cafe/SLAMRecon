// Copyright 2014-2015 Isis Innovation Limited and the authors of InfiniTAM
#ifndef _FE_LIBSETTING_H
#define _FE_LIBSETTING_H

#include "../Objects/FESceneParams.h"
#include "FELibDefines.h"

namespace FE
{
	class FELibSettings
	{
	public:
		/// The device used to run the DeviceAgnostic code
		typedef enum {
			DEVICE_CPU,
			DEVICE_CUDA,
		} DeviceType;

		/// Select the type of device to use
		DeviceType deviceType;

		bool useApproximateRaycast;

		bool useBilateralFilter;

		bool modelSensorNoise;

		/// Tracker types
		typedef enum {
			//! Identifies a tracker based on colour image
			TRACKER_COLOR,
			//! Identifies a tracker based on depth image
			TRACKER_ICP
		} TrackerType;

		/// Select the type of tracker to use
		TrackerType trackerType;

		/// The tracking regime used by the tracking controller
		TrackerIterationType *trackingRegime;

		/// The number of levels in the trackingRegime
		int noHierarchyLevels;

		/// Run ICP till # Hierarchy level, then switch to ITMRenTracker for local refinement.
		int noICPRunTillLevel;

		/// For ITMColorTracker: skip every other point in energy function evaluation.
		bool skipPoints;

		/// For ITMDepthTracker: ICP distance threshold
		float depthTrackerICPThreshold;

		/// For ITMDepthTracker: ICP iteration termination threshold
		float depthTrackerTerminationThreshold;

		/// Further, scene specific parameters such as voxel size
		FE::FESceneParams sceneParams;

		FELibSettings(void);
		~FELibSettings(void);

		// Suppress the default copy constructor and assignment operator
		FELibSettings(const FELibSettings&);
		FELibSettings& operator=(const FELibSettings&);
	};
}

#endif //_FE_LIBSETTING_H