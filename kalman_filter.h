#ifndef KALMAN_FILTER_H_
#define KALMAN_FILTER_H_
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class KalmanFilter {
    public:
    VectorXd x_; //state vector
    MatrixXd P_; //state covariance matrix
    MatrixXd F_; //state transition matrix
    MatrixXd Q_; //process covariance matrix
    MatrixXd H_; //measurement matrix
    MatrixXd R_; //measurement covariance matrix

    KalmanFilter(); //Constructor

    virtual ~KalmanFilter(); //Destructor

    void Predict(); //Predict predicts the state and state covariance matrix using process model

    void Update(const VectorXd &z); //Updates the state and velocity using param z @ time k+1

};

#endif /* KALMAN_FILTER_H_ */
