/**
(C) Copyright 2019 DQ Robotics Developers

This file is part of DQ Robotics.

    DQ Robotics is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    DQ Robotics is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with DQ Robotics.  If not, see <http://www.gnu.org/licenses/>.

Contributors:
- Murilo M. Marinho (murilo@nml.t.u-tokyo.ac.jp)
*/

#include "../dqrobotics_module.h"

void init_DQ_SerialManipulator_py(py::module& m)
{
    /***************************************************
    *  DQ SerialManipulator
    * **************************************************/
    py::class_<DQ_SerialManipulator,DQ_Kinematics> dqserialmanipulator_py(m, "DQ_SerialManipulator");
    dqserialmanipulator_py.def(py::init<MatrixXd, std::string>());
    ///Methods
    dqserialmanipulator_py.def("getDHMatrix",                 &DQ_SerialManipulator::getDHMatrix,"Gets the DH matrix.");
    dqserialmanipulator_py.def("theta",                       &DQ_SerialManipulator::theta,"Retrieves the vector of thetas.");
    dqserialmanipulator_py.def("d",                           &DQ_SerialManipulator::d,"Retrieves the vector d.");
    dqserialmanipulator_py.def("a",                           &DQ_SerialManipulator::a,"Retrieves the vector a.");
    dqserialmanipulator_py.def("alpha",                       &DQ_SerialManipulator::alpha,"Retrieves the vector of alphas.");
    dqserialmanipulator_py.def("get_dim_configuration_space", &DQ_SerialManipulator::get_dim_configuration_space,"Retrieves the number of links.");
    dqserialmanipulator_py.def("convention",                  &DQ_SerialManipulator::convention,"Retrieves the DH convention.");
    //dqserialmanipulator_py.def("base_frame",                  &DQ_SerialManipulator::get_base_frame,"Retrieves the base.");
    //dqserialmanipulator_py.def("reference_frame",             &DQ_SerialManipulator::get_reference_frame,"Retrieves the reference frame");
    dqserialmanipulator_py.def("effector",                    &DQ_SerialManipulator::effector,"Retrieves the effector.");
    //dqserialmanipulator_py.def("set_base_frame",              &DQ_SerialManipulator::set_base_frame,"Sets the base.");
    //dqserialmanipulator_py.def("set_reference_frame",         &DQ_SerialManipulator::set_reference_frame,"Sets the reference frame");
    dqserialmanipulator_py.def("set_effector",                &DQ_SerialManipulator::set_effector,"Sets the effector.");

    dqserialmanipulator_py.def("raw_fkm",                     (DQ (DQ_SerialManipulator::*)(const VectorXd&) const)&DQ_SerialManipulator::raw_fkm,"Gets the raw fkm.");
    dqserialmanipulator_py.def("raw_fkm",                     (DQ (DQ_SerialManipulator::*)(const VectorXd&,const int&) const)&DQ_SerialManipulator::raw_fkm,"Gets the raw fkm.");

    dqserialmanipulator_py.def("fkm",                         (DQ (DQ_SerialManipulator::*)(const VectorXd&) const)&DQ_SerialManipulator::fkm,"Gets the fkm.");
    dqserialmanipulator_py.def("fkm",                         (DQ (DQ_SerialManipulator::*)(const VectorXd&,const int&) const)&DQ_SerialManipulator::fkm,"Gets the fkm.");

    dqserialmanipulator_py.def("raw_pose_jacobian",           (MatrixXd (DQ_SerialManipulator::*)(const VectorXd&, const int&) const)&DQ_SerialManipulator::raw_pose_jacobian,"Returns the pose Jacobian without base or effector transformation");
    dqserialmanipulator_py.def("raw_pose_jacobian",           (MatrixXd (DQ_SerialManipulator::*)(const VectorXd&) const)&DQ_SerialManipulator::raw_pose_jacobian,"Returns the pose Jacobian without base or effector transformation");

    dqserialmanipulator_py.def("pose_jacobian",               (MatrixXd (DQ_SerialManipulator::*)(const VectorXd&, const int&) const)&DQ_SerialManipulator::pose_jacobian,"Returns the pose Jacobian");
    dqserialmanipulator_py.def("pose_jacobian",               (MatrixXd (DQ_SerialManipulator::*)(const VectorXd&) const)&DQ_SerialManipulator::pose_jacobian,"Returns the pose Jacobian");

    dqserialmanipulator_py.def("pose_jacobian_derivative",    (MatrixXd (DQ_SerialManipulator::*)(const VectorXd&, const VectorXd&, const int&) const)&DQ_SerialManipulator::pose_jacobian_derivative,"Returns the derivative of the pose Jacobian");
    dqserialmanipulator_py.def("pose_jacobian_derivative",    (MatrixXd (DQ_SerialManipulator::*)(const VectorXd&, const VectorXd&) const)&DQ_SerialManipulator::pose_jacobian_derivative,"Returns the derivative of the pose Jacobian");
}
