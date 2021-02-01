#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <eigen/Dense>

#include "tracking.h"
#include "measurement_pkg.h"

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::vector;

int main(){
    vector<MeasurementPkg> measurement_pack_list;  //set measurements

    //hardcoded input file with lidar & radar measurements
    string in_filename = "obj_pose-laser-radar-synthetic-input.txt";
    ifstream in_file(in_filename.c_str(), std::ifstream::in);

    if(in_file.is_open()){
        cout << "Cannot open input file" << in_filename << endl;
    }

    string line;
    int i=0;
    while(getline(in_file, line) && (i<=3)){
        MeasurementPkg meas_pkg;
        istringstream iss(line);
        string sensor_type;
        iss >> sensor_type;   //reads first element from current line
        int64_t timestamp;

        if(sensor_type.compare("L") == 0){           //laser meaurement
           //read mesurements
           meas_pkg.sensor_type_ = MeasurementPkg::LIDAR;
           meas_pkg.raw_measurements_ = VectorXd(2);
           float x;
           float y;
           iss >> x;
           iss >> y;
           meas_pkg.raw_measurements_ << x,y ;
           iss >> timestamp;
           meas_pkg.timestamp_ = timestamp;
           measurement_pack_list.push_back(meas_pkg);
        }

        else if(sensor_type.compare("R") == 0){
            //skip radar measurements
            continue;
        }

        i++;

    }

    //create a tracking instance
    Tracking tracking;

    //call the processmeasurement() function for each measurement
    size_t N = measurement_pack_list.size();
    for(size_t k; k<N; ++k){
        tracking.ProcessMeasurement(measurement_pack_list[k]);
    }

    if(in_file.is_open()){
        in_file.close();
    }

    return 0;
}