//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "InterfaceValueUserObject.h"

class InterfaceUserObjectGetMaterialValue;

template <>
InputParameters validParams<InterfaceUserObjectGetMaterialValue>();

/**
 * This userobject collect values of a variable across an interface for each QP and compute a
 * scalar. The computed scalar value depends on the given parameter _interface_value_type\
 * _interface_value_type (see IntervafeValueTools).
 */
class InterfaceUserObjectGetMaterialValue : public InterfaceValueUserObject
{
public:
  static InputParameters validParams();

  InterfaceUserObjectGetMaterialValue(const InputParameters & parameters);
  virtual ~InterfaceUserObjectGetMaterialValue();

  virtual void initialize();
  virtual void execute();
  virtual void finalize() { return; };
  virtual void threadJoin(const UserObject & /*uo*/) { return; };

  Real getQpValue(dof_id_type elem, unsigned int side, unsigned int qp) const;

protected:
  /// this map is used to store QP data.
  std::map<std::pair<dof_id_type, unsigned int>, std::vector<Real>> _map_values;
  const MaterialProperty<Real> & _mp;
  const MaterialProperty<Real> & _mp_neighbor;
};
