//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
// 
// Antioch - A Gas Dynamics Thermochemistry Library
//
// Copyright (C) 2013 The PECOS Development Team
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the Version 2.1 GNU Lesser General
// Public License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor,
// Boston, MA  02110-1301  USA
//
//-----------------------------------------------------------------------el-
//
// $Id$
//
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

#ifndef ANTIOCH_STAT_MECH_THERMO_H
#define ANTIOCH_STAT_MECH_THERMO_H

// C++
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>

// Antioch
#include "antioch/chemical_mixture.h"
#include "antioch/input_utils.h"
#include "antioch/metaprogramming.h"
#include "antioch/antioch_exceptions.h"

namespace Antioch
{

  template<typename CoeffType=double>
  class StatMechThermodynamics
  {
  public:
    
    StatMechThermodynamics( const ChemicalMixture<CoeffType>& chem_mixture );

    //! Destructor
    /*! virtual so this can be subclassed by the user. */
    virtual ~StatMechThermodynamics();

    /**
     * @returns species translational/rotational specific heat at
     * constant volume.
     */
    CoeffType cv_tr (const unsigned int species) const;

      
    /**
     * @returns mixture translational/rotational specific heat at
     * constant volume.
     */
    template<typename StateType>
    StateType cv_tr (const std::vector<StateType>& mass_fractions) const;
      
    /**
     * @returns species vibrational specific heat
     * constant volume.
     */
    template<typename StateType>
    StateType cv_vib (const unsigned int species, const StateType Tv) const;
      
    /**
     * @returns mixture vibrational specific heat
     * constant volume.
     */
    template<typename StateType>
    StateType cv_vib (const StateType Tv, const std::vector<StateType>& mass_fractions) const;

    /**
     * @returns species electronic specific heat at constant volume.
     */
    template<typename StateType>
    StateType cv_el (const unsigned int species, const StateType Te) const;
      
    /**
     * @returns mixture electronic specific heat at constant volume.
     */
    template<typename StateType>
    StateType cv_el (const StateType Te, const std::vector<StateType>& mass_fractions) const;
      
    /**
     * @returns species vibrational/electronic specific heat
     * constant volume.
     */
    template<typename StateType>
    StateType cv_ve (const unsigned int species, const StateType Tv) const;
      
    /**
     * @returns mixture vibrational/electronic specific heat
     * constant volume.
     */
    template<typename StateType>
    StateType cv_ve (const StateType Tv, const std::vector<StateType>& mass_fractions) const;
      
    /**
     * @returns species total specific heat at constant volume, J/kg. Note that the input
     * translational/rotational temperature is currently not used, as these
     * modes are assumed to be fully excited.  However, the API is here
     * in case this assumption is removed later.
     */
    template<typename StateType>
    StateType cv (const unsigned int species, const StateType T, const StateType Tv) const;
      
    /**
     * @returns mixture total specific heat at constant volume, J/kg. Note that the input
     * translational/rotational temperature is currently not used, as these
     * modes are assumed to be fully excited.  However, the API is here
     * in case this assumption is removed later.
     */
    template<typename StateType>
    StateType cv (const StateType T, const StateType Tv, const std::vector<StateType>& mass_fractions) const;

    /**
     * @returns mixture total specific heat at constant pressure, J/kg.
     */
    template<typename StateType>
    StateType cp (const StateType T, const StateType Tv, const std::vector<StateType>& mass_fractions) const;

    /**
     * @returns species total enthalpy, J/kg.
     */
    template<typename StateType>
    StateType h_tot (const unsigned int species, const StateType T, const StateType Tv) const;

    /**
     * @returns species total enthalpy, J/kg.  Assumes thermal equilibrium
     * of translational/rotational and vibrational/electronic temperature.
     */
    template<typename StateType>
    StateType h_tot (const unsigned int species, const StateType T) const;

    /**
     * @returns mixture specific enthalpy, J/kg.
     */
    template<typename StateType>
    StateType h_tot (const StateType T, const StateType Tv, const std::vector<StateType>& mass_fractions) const;

    /**
     * @returns mixture specific enthalpy, J/kg. Assumes thermal equilibrium
     * of translational/rotational and vivbrational/electronic temperature.
     */
    template<typename StateType>
    StateType h_tot (const StateType T, const std::vector<StateType>& mass_fractions) const;
      
    /**
     * @returns species total internal energy, J/kg.
     */
    template<typename StateType>
    StateType e_tot (const unsigned int species, const StateType T, const StateType Tv) const;

    /**
     * @returns mixture total internal energy, J/kg.
     */
    template<typename StateType>
    StateType e_tot (const StateType T, const StateType Tv, const std::vector<StateType>& mass_fractions) const;
      
    /**
     * @returns species total internal energy, J/kg.  Assumes thermal equilibrium
     * of translational/rotational and vibrational/electronic temperature.
     */
    template<typename StateType>
    StateType e_tot (const unsigned int species, const StateType T) const;

    /**
     * @returns mixture total internal energy, J/kg.  Assumes thermal equilibrium
     * of translational/rotational and vivbrational/electronic temperature.
     */
    template<typename StateType>
    StateType e_tot (const StateType T, const std::vector<StateType>& mass_fractions) const;
      
    /**
     * @returns species translational/rotational energy, J/kg.
     */
    template<typename StateType>
    StateType e_tr (const unsigned int species, const StateType T) const;
      
    /**
     * @returns mixture translational/rotational energy, J/kg.
     */
    template<typename StateType>
    StateType e_tr (const StateType T, const std::vector<StateType>& mass_fractions) const;

    /**
     * @returns species vibrational energy, J/kg.
     */
    template<typename StateType>
    StateType e_vib (const unsigned int species, const StateType Tv) const;

    /**
     * @returns mixture vibrational energy, J/kg.
     */
    template<typename StateType>
    StateType e_vib (const StateType Tv, const std::vector<StateType>& mass_fractions) const;

    /**
     * @returns species electronic energy, J/kg.
     */
    template<typename StateType>
    StateType e_el (const unsigned int species, const StateType Te) const;

    /**
     * @returns mixture electronic energy, J/kg.
     */
    template<typename StateType>
    StateType e_el (const StateType Te, const std::vector<StateType>& mass_fractions) const;
      
    /**
     * @returns species vibrational/electronic energy, J/kg.
     */
    template<typename StateType>
    StateType e_ve (const unsigned int species, const StateType Tv) const;
      
    /**
     * @returns mixture vibrational/electronic energy, J/kg.
     */
    template<typename StateType>
    StateType e_ve (const StateType Tv, const std::vector<StateType>& mass_fractions) const;

    /**
     * @returns the minimum valid mixture vibrational/electronic energy, J/kg.
     * We allow for a user-specified minimum vibrational temperature, Tv.
     * This in turn sets an a priori minimum valid species 
     * vibrational/electronic temperature.  However, the minimum valid
     * value for a mixture depends on the species mass fractions and must
     * be computed.  That is what this method does.
     */
    CoeffType e_ve_min () const;

    /**
     * @returns mixture vibrational/electronic energy (same as
     * e_ve()) and specific heat (same as cv_ve()), calculated
     * together for efficiency.
     */
    template<typename StateType>
    void e_and_cv_ve (const StateType Tv, const std::vector<StateType>& mass_fractions,
                      StateType &e_ve, StateType &cv_ve) const;
      
    /**
     * @returns species formation energy, J/kg.
     */
    CoeffType e_0 (const unsigned int species) const;
      
    /**
     * @returns mixture formation energy, J/kg.
     */
    template<typename StateType>
    StateType e_0 (const std::vector<StateType>& mass_fractions) const;
      
    /**
     * Computes the mixture vibrational temperature (K) from input
     * vibrational-electronic energy per unit mass (J/kg).
     */
    template<typename StateType>
    StateType Tv_from_e_ve (const StateType e_ve, const std::vector<StateType>& mass_fractions,
                            StateType Tv = -1.) const;
      
    /**
     * Computes the mixture temperature (K) from input
     * total energy per unit mass (J/kg).
     */
    template<typename StateType>
    StateType T_from_e_tot (const StateType e_tot, const std::vector<StateType>& mass_fractions,
                            StateType T = -1.) const;
      
    /**
     * Computes the mixture temperature (K) from input
     * translational/rotational energy per unit mass (J/kg).
     */
    template<typename StateType>
    StateType T_from_e_tr (const StateType e_tr, const std::vector<StateType>& mass_fractions,
                           StateType T = -1.) const;
      
    /**
     * Computes the mixture temperature (K) from input
     * enthalpy per unit mass (J/kg).
     */
    template<typename StateType>
    StateType T_from_h_tot (const StateType h_tot, const std::vector<StateType>& mass_fractions,
                            StateType T = -1.) const;
    
    /**
     * Computes the mixture temperature (K) from input
     * vibrational/electronic temperature Tv (K) and
     * enthalpy per unit mass (J/kg).
     */
    template<typename StateType>
    StateType T_from_h_tot_Tv (const StateType h_tot, const StateType Tv, const std::vector<StateType>& mass_fractions,
                               StateType T = -1.) const;
    
    /**
     * Computes the mixture specific entropy (J/kg-K) from input
     * temperature (K) and pressure (Pa).
     */
    template<typename StateType>
    StateType s (const StateType T, const StateType p, const std::vector<StateType>& mass_fractions) const;

  protected:

    const ChemicalMixture<CoeffType>& _chem_mixture;

  private:
    
    //! Default constructor
    /*! Private to force to user to supply a ChemicalMixture object.*/
    StatMechThermodynamics();
  };

  
  /* ------------------------- Inline Functions -------------------------*/
  
  template<typename CoeffType>
  inline
  StatMechThermodynamics<CoeffType>::StatMechThermodynamics( const ChemicalMixture<CoeffType>& chem_mixture )
    : _chem_mixture(chem_mixture)
  {
    /*! \todo Read all necessary data */
  }

  template<typename CoeffType>
  inline
  StatMechThermodynamics<CoeffType>::~StatMechThermodynamics ()
  {
    // NOP
  }

  template<typename CoeffType>
  inline
  CoeffType StatMechThermodynamics<CoeffType>::cv_tr (const unsigned int species) const
  {
    return _chem_mixture.R(species)*(_chem_mixture.chemical_species()[species])->n_tr_dofs();
  }

  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::cv_tr (const std::vector<StateType>& mass_fractions) const
  {
    StateType cv_tr = mass_fractions[0]*this->cv_tr(0);

    for( unsigned int s = 1; s < _chem_mixture.n_species(); s++ )
      {
        cv_tr += mass_fractions[s]*this->cv_tr(s);
      }
    
    return cv_tr;
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::cv_vib (const unsigned int species, 
                                                       const StateType Tv) const
  {
    // convenience
    const ChemicalSpecies<CoeffType>& chem_species = *(_chem_mixture.chemical_species()[species]);
    const std::vector<CoeffType>& theta_v  = chem_species.theta_v();
    const std::vector<unsigned int>& ndg_v = chem_species.ndg_v();
    
    antioch_assert_equal_to(ndg_v.size(), theta_v.size());
    
    // Use an input datum to make sure we get the size right
    StateType cv_vib = Antioch::zero_clone(Tv);
	
    if (theta_v.empty())
      return cv_vib;

    for (unsigned int level=0; level<ndg_v.size(); level++)
      {
        const StateType expval = std::exp(theta_v[level]/Tv);
      
        cv_vib += (static_cast<CoeffType>(ndg_v[level])*
                   chem_species.gas_constant()*theta_v[level]*theta_v[level]*expval/(expval - 1.)/(expval - 1.)/Tv/Tv);
      }
    
    return cv_vib;
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::cv_vib (const StateType Tv,
                                                       const std::vector<StateType>& mass_fractions) const
  {
    StateType cv_vib = mass_fractions[0]*this->cv_vib(0, Tv);

    for( unsigned int s = 1; s < _chem_mixture.n_species(); s++ )
      {
        cv_vib += mass_fractions[s]*this->cv_vib(s, Tv);
      }
    
    return cv_vib;
  }

  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::cv_el (const unsigned int species, 
                                                      const StateType Te) const
  {
    // convenience
    const ChemicalSpecies<CoeffType>& chem_species = *(_chem_mixture.chemical_species()[species]);
    const std::vector<CoeffType>& theta_e  = chem_species.theta_e();
    const std::vector<unsigned int>& ndg_e = chem_species.ndg_e();
    
    antioch_assert_equal_to(ndg_e.size(), theta_e.size());
    
    StateType cv_el = 0.0;
    
    // Really < 2?  Yes, b/c theta_e[0] = 0.0 always.  See
    // read_species_electronic_data_ascii_default in
    // species_ascii_parsing.h
    if (theta_e.size() < 2) return cv_el;
    
    const StateType Teinv = 1./Te;
    const StateType Te2inv = Teinv*Teinv;
    
    StateType
      num = 0., dnum = 0.,
      den = 0., dden = 0.;
    
    for (unsigned int level=0; level<theta_e.size(); level++)
      {
        const StateType 
          expval = std::exp (-theta_e[level] * Teinv),
          den_l  = static_cast<StateType>(ndg_e[level])*expval,
          num_l  = den_l*theta_e[level],
          dden_l = num_l*Te2inv,
          dnum_l = dden_l*theta_e[level];
        
        num  += num_l;
        den  += den_l;
	
        dden += dden_l;
        dnum += dnum_l;
      }
    
    const StateType invden = 1./den;
    
    cv_el = chem_species.gas_constant()*(dnum - num*dden*invden) * invden;

    return cv_el;
  }
  
  template<typename CoeffType>
  template<typename StateType>
  StateType StatMechThermodynamics<CoeffType>::cv_el (const StateType Te, 
                                                      const std::vector<StateType>& mass_fractions) const
  {
    StateType cv_el = mass_fractions[0]*this->cv_el(0, Te);

    for( unsigned int s = 1; s < _chem_mixture.n_species(); s++ )
      {
        cv_el += mass_fractions[s]*this->cv_el(s, Te);
      }
    
    return cv_el;
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::cv_ve (const unsigned int species, 
                                                      const StateType Tv) const
  {
    return (this->cv_vib(species, Tv) + this->cv_el(species, Tv));
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::cv_ve (const StateType Tv,
                                                      const std::vector<StateType>& mass_fractions) const
  {
    return (this->cv_vib(Tv, mass_fractions) + this->cv_el(Tv, mass_fractions));
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::cv (const unsigned int species, 
                                                   const StateType /* T */, 
                                                   const StateType Tv) const
  {
    return (this->cv_tr(species) + this->cv_ve(species, Tv));
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::cv (const StateType /* T */, 
                                                   const StateType Tv,
                                                   const std::vector<StateType>& mass_fractions) const
  {
    return (this->cv_tr(mass_fractions) + this->cv_ve(Tv, mass_fractions));
  }

  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::cp (const StateType T, 
                                                   const StateType Tv,
                                                   const std::vector<StateType>& mass_fractions) const
  {
    return (this->cv(T,Tv,mass_fractions) + this->_chem_mixture.R(mass_fractions));
  }

  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::h_tot (const unsigned int species, 
                                                      const StateType T, 
                                                      const StateType Tv) const
  {
    const ChemicalSpecies<CoeffType>& chem_species = *(_chem_mixture.chemical_species()[species]);
    return (this->e_tot(species, T, Tv) + chem_species.gas_constant()*T);
  }


  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::h_tot (const unsigned int species, 
                                                      const StateType T) const
  {
    return this->h_tot(species, T, T);
  }

  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::h_tot (const StateType T, 
                                                      const StateType Tv,
                                                      const std::vector<StateType>& mass_fractions) const
  {
    StateType h_tot = mass_fractions[0]*this->h_tot(0, T, Tv);

    for( unsigned int s = 1; s < _chem_mixture.n_species(); s++ )
      {
        h_tot += mass_fractions[s]*this->h_tot(s, T, Tv);
      }
    
    return h_tot;
  }

  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::h_tot (const StateType T,
                                                      const std::vector<StateType>& mass_fractions) const
  {
    return this->h_tot(T, T, mass_fractions);
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_tot (const unsigned int species, 
                                                      const StateType T, 
                                                      const StateType Tv) const
  {
    return (this->e_tr(species, T) + this->e_ve(species, Tv) + this->e_0(species));
  }


  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_tot (const StateType T, 
                                                      const StateType Tv,
                                                      const std::vector<StateType>& mass_fractions) const
  {
    return (this->e_tr(T, mass_fractions) + this->e_ve(Tv, mass_fractions) + this->e_0(mass_fractions));
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_tot (const unsigned int species, 
                                                      const StateType T) const
  {
    return this->e_tot(species, T, T);
  }

  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_tot (const StateType T,
                                                      const std::vector<StateType>& mass_fractions) const
  {
    return this->e_tot(T, T, mass_fractions);
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_tr (const unsigned int species, 
                                                     const StateType T) const
  {
    return this->cv_tr(species)*T;
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_tr (const StateType T,
                                                     const std::vector<StateType>& mass_fractions) const
  {
    StateType e_tr = mass_fractions[0]*this->e_tr(0, T);

    for( unsigned int s = 1; s < _chem_mixture.n_species(); s++ )
      {
        e_tr += mass_fractions[s]*this->e_tr(s, T);
      }
    
    return e_tr;
  }

  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_vib (const unsigned int species, 
                                                      const StateType Tv) const
  {
    // convenience
    const ChemicalSpecies<CoeffType>& chem_species = *(_chem_mixture.chemical_species()[species]);
    const std::vector<CoeffType>& theta_v  = chem_species.theta_v();
    const std::vector<unsigned int>& ndg_v = chem_species.ndg_v();
    
    antioch_assert_equal_to(ndg_v.size(), theta_v.size());
    
    StateType e_vib = 0.0;

    if (theta_v.empty()) return e_vib;
    
    for (unsigned int level=0; level<ndg_v.size(); level++)
      e_vib += ndg_v[level]*chem_species.gas_constant()*theta_v[level]/(std::exp(theta_v[level]/Tv) - 1.);
    
    return e_vib;
  }

  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_vib (const StateType Tv,
                                                      const std::vector<StateType>& mass_fractions) const
  {
    StateType e_vib = mass_fractions[0]*this->e_vib(0, Tv);

    for( unsigned int s = 1; s < _chem_mixture.n_species(); s++ )
      {
        e_vib += mass_fractions[s]*this->e_vib(s, Tv);
      }
    
    return e_vib;
  }

  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_el (const unsigned int species, const StateType Te) const
  {
    // convenience
    const ChemicalSpecies<CoeffType>& chem_species = *(_chem_mixture.chemical_species()[species]);
    const std::vector<CoeffType>& theta_e  = chem_species.theta_e();
    const std::vector<unsigned int>& ndg_e = chem_species.ndg_e();
    
    antioch_assert_equal_to(ndg_e.size(), theta_e.size());

    StateType e_el = 0.0;

    if (theta_e.size() < 2) return e_el;

    StateType num = 0., den = 0.;
    
    for (unsigned int level=0; level<theta_e.size(); level++)
      {
        const StateType expval = std::exp (-theta_e[level] / Te);
        num += static_cast<StateType>(ndg_e[level])*theta_e[level]*expval;
        den += static_cast<StateType>(ndg_e[level])*expval;	  
      }
    
    return chem_species.gas_constant() * num / den;
  }

  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_el (const StateType Te, const std::vector<StateType>& mass_fractions) const
  {
    StateType e_el = mass_fractions[0]*this->e_el(0, Te);

    for( unsigned int s = 1; s < _chem_mixture.n_species(); s++ )
      {
        e_el += mass_fractions[s]*this->e_el(s, Te);
      }
    
    return e_el;
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_ve (const unsigned int species, 
                                                     const StateType Tv) const
  {
    return (this->e_vib(species,Tv) + this->e_el(species,Tv));
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_ve (const StateType Tv,
                                                     const std::vector<StateType>& mass_fractions) const
  {
    return (this->e_vib(Tv,mass_fractions) + this->e_el(Tv,mass_fractions));
  }

  template<typename CoeffType>
  inline
  CoeffType StatMechThermodynamics<CoeffType>::e_ve_min () const
  {
    antioch_not_implemented();
  }

  template<typename CoeffType>
  template<typename StateType>
  inline
  void StatMechThermodynamics<CoeffType>::e_and_cv_ve (const StateType Tv,
                                                       const std::vector<StateType>& mass_fractions,
                                                       StateType &e_ve, 
                                                       StateType &cv_ve) const
  {
    e_ve  = this->e_ve (Tv, mass_fractions);
    cv_ve = this->cv_ve(Tv, mass_fractions);
  }
      
  template<typename CoeffType>
  inline
  CoeffType StatMechThermodynamics<CoeffType>::e_0 (const unsigned int species) const
  {
    const ChemicalSpecies<CoeffType>& chem_species = *(_chem_mixture.chemical_species()[species]);
    return chem_species.formation_enthalpy();
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::e_0 (const std::vector<StateType>& mass_fractions) const
  {
    StateType e_0 = mass_fractions[0]*this->e_0(0);
    
    for( unsigned int s = 1; s < _chem_mixture.n_species(); s++ )
      {
        e_0 += mass_fractions[s]*this->e_0(s);
      }
    
    return e_0;
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::Tv_from_e_ve (const StateType e_ve, 
                                                             const std::vector<StateType>& mass_fractions,
                                                             StateType Tv ) const
  {
    antioch_not_implemented();
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::T_from_e_tot (const StateType e_tot, 
                                                             const std::vector<StateType>& mass_fractions,
                                                             StateType T ) const
  {
    // Cache the translational/rotational specific heat - this will be used repeatedly 
    // and involves (2*NS-1) flops to compute, and since this has no functional 
    // dependence on temperature it will not change throughout the Newton iteration.
    const StateType Cv_tr = this->cv_tr(mass_fractions);

    // Similarly for mixture formation energy
    const StateType E_0 = this->e_0(mass_fractions);

    // if the user does not provide an initial guess for the temperature
    // assume it is all in translation/rotation to compute a starting value.
    if (T < 0.)
      {
	T = (e_tot - E_0) / Cv_tr;
	T = std::min(std::max(T,StateType(10.)),StateType(20000.));
	
        // FIXME: Use Antioch::Limits or similar? (i.e., don't
        // hardcode min and max T)

	// make sure the initial guess is valid
	//T = std::max(T, Limits::CompNSLimits::T_min());
        T = std::max(T, StateType(10.));
	T = std::min(T, StateType(2.e4));
      }
    
    // compute the translational/rotational temperature of the mixture using Newton-Rhapson iteration
    StateType delta_T = std::numeric_limits<StateType>::max();
    const unsigned int max_iterations = 100;

    const CoeffType dT_reltol= std::numeric_limits<CoeffType>::epsilon() * 100;
    
    // NOTE: FIN-S uses a hardcoded, absolute tolerance on delta_T of
    // 1e-8.  Using a relative tolerance here of 100*epsilon.
    for (unsigned int iter = 0;
         std::abs(delta_T/T) > dT_reltol &&
         T >= 0.;
         ++iter)
      {
	if (iter == max_iterations)
	  throw FailedNewtonTTvInversion ("ERROR: failed to converge T_from_e_tot!");
	
	// compute the residual, defined as the mismatch between the input e_tot and
	// the value corresponding to the current T iterate
        StateType Re = 0., dRevdT = 0.;
        this->e_and_cv_ve(T, mass_fractions, Re, dRevdT);
        Re += this->e_tr(T, mass_fractions) + E_0 - e_tot;
        dRevdT += Cv_tr;

	delta_T = -Re / dRevdT;
	T += delta_T;
      }

    return T;
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::T_from_e_tr (const StateType e_tr, 
                                                            const std::vector<StateType>& mass_fractions,
                                                            StateType T ) const
  {
    antioch_not_implemented();
  }
      
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::T_from_h_tot (const StateType h_tot, 
                                                             const std::vector<StateType>& mass_fractions,
                                                             StateType T ) const
  {
    antioch_not_implemented();
  }
    
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::T_from_h_tot_Tv (const StateType h_tot, 
                                                                const StateType Tv, 
                                                                const std::vector<StateType>& mass_fractions,
                                                                StateType T ) const
  {
    antioch_not_implemented();
  }

    
  template<typename CoeffType>
  template<typename StateType>
  inline
  StateType StatMechThermodynamics<CoeffType>::s (const StateType T, 
                                                  const StateType p,
                                                  const std::vector<StateType>& mass_fractions) const
  {
    antioch_not_implemented();
  }

} // end namespace Antioch

#endif // ANTIOCH_STAT_MECH_THERMO_H
