//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "GeneralReporter.h"

/**
 * Report the time and iteration information for the simulation.
 */
class IterationInfo : public GeneralReporter
{
public:
  static InputParameters validParams();
  IterationInfo(const InputParameters & parameters);
  virtual void initialize() override {}
  virtual void finalize() override {}
  virtual void execute() override;

protected:
  Real & _time_value;
  unsigned int & _time_step_value;
  unsigned int & _num_linear;
  unsigned int & _num_nonlinear;
};
