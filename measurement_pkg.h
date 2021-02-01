#pragma once

#include <Eigen/Dense>

class MeasurementPkg {
    public:
    int64_t timestamp_;

    enum SensorType {
        LIDAR, RADAR
    } sensor_type_;

    Eigen::VectorXd raw_measurements_;
};

