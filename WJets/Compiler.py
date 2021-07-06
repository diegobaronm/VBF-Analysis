# This script compiles the code before executing the jobs
import ROOT as r

r.gROOT.ProcessLine(".L MC/backend/CLoop.C++")
r.gROOT.ProcessLine(".L DATA/backend/CLoop.C++")