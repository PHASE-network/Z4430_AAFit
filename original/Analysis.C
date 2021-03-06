//
//  Analysis.C
//  
//  A simple AA analysis code.
//  Created by Ivan Heredia de la Cruz on 4/25/16.
//
//

#include "RooGlobalFunc.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
#include "TROOT.h"
#include "TMath.h"

#include "RooFitResult.h"

#include "myPDF.h"

using namespace RooFit ;


void Analysis()
{

    
    RooRealVar a1600L0S1("a1600L0S1","a1600L0S1",0.64);
    RooRealVar b1600L0S1("b1600L0S1","b1600L0S1",0);
    RooRealVar a1600L1S1("a1600L1S1","a1600L1S1",0.64);
    RooRealVar b1600L1S1("b1600L1S1","b1600L1S1",0);
    RooRealVar a1600L1S3("a1600L1S3","a1600L1S3",0.64);
    RooRealVar b1600L1S3("b1600L1S3","b1600L1S3",0);
    RooRealVar a1600L2S3("a1600L2S3","a1600L2S3",0.64);
    RooRealVar b1600L2S3("b1600L2S3","b1600L2S3",0);
    RooRealVar a1670L0S1("a1670L0S1","a1670L0S1",0.0145);
    RooRealVar b1670L0S1("b1670L0S1","b1670L0S1",0);
    RooRealVar a1670L1S1("a1670L1S1","a1670L1S1",0.0145);
    RooRealVar b1670L1S1("b1670L1S1","b1670L1S1",0);
    RooRealVar a1670L1S3("a1670L1S3","a1670L1S3",0.0145);
    RooRealVar b1670L1S3("b1670L1S3","b1670L1S3",0);
    RooRealVar a1670L2S3("a1670L2S3","a1670L2S3",0.0145);
    RooRealVar b1670L2S3("b1670L2S3","b1670L2S3",0);
    
    RooRealVar mKp("mKp","mKp",1.6,1.44,2.52);
    RooRealVar cLb("cLb","cLb",0.5,-1,1);
    RooRealVar cJ("cJ","cJ",0.5,-1,1);
    RooRealVar cLs("cLs","cLs",0.5,-1,1);
    RooRealVar phiMu("phiMu","phiMu",0.25,-TMath::Pi(),TMath::Pi());
    RooRealVar phiK("phiK","phiK",0.25,-TMath::Pi(),TMath::Pi());

    myPDF pdf("pdf","pdf",mKp,cLb,cJ,cLs,phiMu,phiK,
                 a1600L0S1, b1600L0S1, a1600L1S1, b1600L1S1, a1600L1S3, b1600L1S3, a1600L2S3, b1600L2S3, a1670L0S1, b1670L0S1, a1670L1S1, b1670L1S1, a1670L1S3, b1670L1S3, a1670L2S3, b1670L2S3 ) ;
    

    // Generate toy data from pdf and plot data and p.d.f on frame
    RooDataSet* data = pdf.generate(RooArgSet(mKp,cLb,cJ,cLs,phiMu,phiK),2000) ;

    //RooFitResult* fitres = pdf.fitTo(*data,Hesse(kTRUE),Minos(kFALSE),Save(kTRUE)) ;
    //fitres->Print("v");
    
    
    RooPlot* frameKp = mKp.frame() ;
    data->plotOn(frameKp) ;
    pdf.plotOn(frameKp) ;
    
    TCanvas* canvasmKp = new TCanvas("canvasmKp","canvasmKp",800,600) ;
    canvasmKp->cd();
    frameKp->Draw() ;
    
    //Here you can also project other variables.

    RooPlot* frame_cLs = cLs.frame() ;
    data->plotOn(frame_cLs) ;
    pdf.plotOn(frame_cLs) ;
    
    TCanvas* canvascLs = new TCanvas("canvascLs","canvascLs",800,600) ;
    canvascLs->cd();
    frame_cLs->Draw() ;

}
