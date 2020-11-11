# SET_CPP_TP1
A studies practical work including creating  mathematical sets(Ensemble) and do some operations.
Attributes:
  * cardAct: The actual cardinality of the set (the number of elements present in the set)
  * cardMaximale: The maximum cardinality of the set (the number of elements you can have in the set)
  * tab: the set.

## Ensemble.h
The headers file including all the declarations of the parameters and methods used:
  * EstEgal: returns true if the set is equal to the set in parameters.;
  * EstInclus: 
       * Returns *NON_INCLUSION* if the set is not included. 
       * Returns *INCLUSION_LARGE* if the set is included and equal.
       * Returns *INCLUSION_STRICTE* if the set is included but not equal.
  * Ajouter: adds an element to the set: 
       * Returns *DEJA_PRESENT* if the number is already in the set.
       * Returns *PLEIN* if the set is already full.
       * Returns *AJOUTE* if the number got added successfuly.
  * Ajuster: takes a number delta as a parameter and returns the cardMaximale after the changes:
       * If delta is positive adjusts cardMaximale+= delta.
       * If delta is negative adjusts cardMaximale-= delta such as it stops at cardAct to not remove elements.
  * Retirer(int): removes the element taken in parameters:
       * Returns true if the element got successfuly removed.
       * Returns false if the element didn't get removed.
  * Retirer (Ensemble) : removes the elements present in the set of the parameters from the actual set.
  * Intersection: Changes the effective set to the intersection with the set in parameters.
