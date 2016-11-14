/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef DALITZ_CONTOUR
#define DALITZ_CONTOUR

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"

#include "myPDF.h"
 
class Dalitz_contour : public RooAbsPdf {
public:
  Dalitz_contour() {} ; 
  Dalitz_contour(const char *name, const char *title,
		 RooAbsReal& _mKP,
		 RooAbsReal& _mPsiP,
		 const Bool_t _massSquared,
		 const TString& _psi_nS
		 );
  Dalitz_contour(const Dalitz_contour& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new Dalitz_contour(*this,newname); }
  inline virtual ~Dalitz_contour() { }

protected:

  RooRealProxy mKP ;
  RooRealProxy mPsiP ;
  
  Double_t evaluate() const ;

private:
  Bool_t massSquared;
  TString psi_nS;

  ClassDef(Dalitz_contour,1) // Your description goes here...
};
 
#endif
