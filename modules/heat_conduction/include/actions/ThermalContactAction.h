//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "Action.h"

#include "MooseEnum.h"

class ThermalContactAction : public Action
{
public:
  static InputParameters validParams();

  ThermalContactAction(const InputParameters & params);
  virtual void act() override;

protected:
  virtual void addAuxKernels();
  virtual void addAuxVariables();
  virtual void addBCs();
  virtual void addDiracKernels();
  virtual void addMaterials();
  virtual void addSecondaryFluxVector();

  const bool _quadrature;
  const MooseEnum _order;
  const AuxVariableName _penetration_var_name;
  const AuxVariableName _gap_value_name;
  const AuxVariableName _gap_conductivity_name;

  const std::vector<BoundaryName> _primary_name;
  const std::vector<BoundaryName> _secondary_name;

  /// Number of contact pairs on which to enable thermal contact
  const unsigned int _number_pairs;
};
