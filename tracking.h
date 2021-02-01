#ifndef TRACKING_H_
#define TRACKING_H_

#include "measurement_pkg.h"
#include <vector>
#include <fstream>
#include <string>
#include "kalman_filter.h"

class Tracking {
    public:
    Tracking();
    virtual ~Tracking();
    void ProcessMeasurement(const MeasurementPkg &measurement_pack);
    KalmanFilter kf_;

    private:
    bool is_initialized_;
    int64_t previous_timestamp_;

    //acceleration noise components
    float noise_ax;
    float noise_ay;


};

#endif /* TRACKING_H_ */