#!/bin/bash
begin="arguments from "
condor_submit Condor.sub -queue ${begin}${1}
