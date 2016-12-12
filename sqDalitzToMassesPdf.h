/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef SQDALITZTOMASSESPDF
#define SQDALITZTOMASSESPDF

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
 
class sqDalitzToMassesPdf : public RooAbsPdf {
public:
  sqDalitzToMassesPdf() {} ; 
  sqDalitzToMassesPdf(const char *name, const char *title,
		      RooAbsReal& _x,
		      RooAbsReal& _y,
		      const RooAbsPdf *_squareDalitz,
		      RooRealVar* _cosKstar,
		      const Double_t _MPsi_nS
		      );
  sqDalitzToMassesPdf(const sqDalitzToMassesPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new sqDalitzToMassesPdf(*this,newname); }
  inline virtual ~sqDalitzToMassesPdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy y ;
  const RooAbsPdf *squareDalitz ;
  RooRealVar* cosKstar;
  Double_t MPsi_nS ;

  Double_t evaluate() const ;

private:

  ClassDef(sqDalitzToMassesPdf,1) // Your description goes here...
};
 
#endif
