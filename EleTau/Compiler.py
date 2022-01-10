# This script compiles the code before executing the jobs
import ROOT as r
import sys

r.gROOT.ProcessLine(".L "+sys.argv[1]+"/backend/CLoop.C++")