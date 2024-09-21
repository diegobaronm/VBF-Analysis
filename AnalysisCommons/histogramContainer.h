#ifndef histogramContainer_h
#define histogramContainer_h

#include"Tools.h"
#include<iostream>

// Struct to store a set of histograms for a given variable. It stores histograms for sequential cutflows.
// cutBit option allows to store a histogram for a specific cut that is satisfied or not while all the others are.
struct histogramContainer
{
    TH1F* m_histos;
    int m_nBins{};
    double m_xMin{};
    double m_xMax{};
    std::string m_baseName{""};
    int m_numberHistos{};
    std::string m_description{""};
    std::string m_cutBit{""};
    std::vector<std::string> m_cutLabels{""};

    // Constructor for a set of histograms with a defined cutflow.
    histogramContainer(const std::string& baseName, const std::string& description,
    int nBins, double xMin, double xMax, 
    const std::vector<std::string>& cutLabels, const std::string& cutBit = "") : 
    m_baseName{baseName}, m_nBins{nBins}, m_xMin{xMin}, m_xMax{xMax}, m_description{description}, m_cutLabels{cutLabels}, m_cutBit{cutBit}
    {
        bool relevantCut = !m_cutBit.empty(); // Produce a histogram of a cut passed or not while all the others are.
        m_numberHistos = relevantCut ? cutLabels.size()+1 : cutLabels.size();
        m_histos = new TH1F[m_numberHistos];
        std::string name{m_baseName};
        for (int i{0}; i < m_numberHistos; i++)
        {
            if (relevantCut)
            {
                m_histos[i] = TH1F(name.c_str(),m_description.c_str(),m_nBins,m_xMin,m_xMax);
                if (i != m_numberHistos-1){name = name +"_" + cutLabels[i];}
                
            } else {
                name = name +"_" + cutLabels[i];
                m_histos[i] = TH1F(name.c_str(),m_description.c_str(),m_nBins,m_xMin,m_xMax);
            }
            
        }
    }
    // Filling function : it feels all the histograms all at once taking into account the results passed by a vector of bits.
    void Fill(double value, double weight, const std::vector<int>& cutBits)
    {   
        //First check that the size of the passed cutBits is consistent with the number of cutLabels.
        if (cutBits.size() != m_cutLabels.size())
        {
            g_LOG(LogLevel::ERROR, "The size of the cuts vector passed is not consistent with the definition in Analysis.h");
            g_LOG(LogLevel::ERROR, "Bad histogram: " , m_baseName);
            exit(1);
        }
        bool relevantCut = !m_cutBit.empty();
        int numberPassedCuts{cutBits[0]};
        if (!relevantCut)
        {
            for (int i{0}; i < m_numberHistos; i++)
            {
                if (cutBits[i] == 1 && numberPassedCuts == i+1)
                {
                    numberPassedCuts++;
                    m_histos[i].Fill(value,weight);
                } else {
                    break;
                }
            }
        } else {
            size_t sum{0};
            for(auto &j : cutBits){sum=sum+j;}
            bool passedAllCuts = (sum == cutBits.size());
            auto it = std::find(m_cutLabels.begin(),m_cutLabels.end(),m_cutBit);
            int indexOfRelevantVariable = it-m_cutLabels.begin();
            bool passedRelevantCut = cutBits.at(indexOfRelevantVariable) == 1 ? true : false;
            bool passedAllCutsButRelevantCut = (sum == cutBits.size()-1) && !passedRelevantCut;
            if (passedAllCutsButRelevantCut || passedAllCuts)
            {
                m_histos[0].Fill(value,weight);
            }
            for (int i{1}; i < m_numberHistos; i++)
            {
                if (cutBits[i-1] == 1 && numberPassedCuts == i)
                {
                    numberPassedCuts++;
                    m_histos[i].Fill(value,weight);
                } else {
                    break;
                }
            }
        }
        
    }
    // Write all histograms to the current directory.
    void Write()
    {
        for (int i{0}; i < m_numberHistos; i++)
        {
            m_histos[i].Write();
        }
    }
    // Clean memory on destruction.
    ~histogramContainer()
    {
        delete[] m_histos;
    }
};

#endif