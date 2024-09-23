#ifndef histogramContainer_h
#define histogramContainer_h

#include"Tools.h"
#include<iostream>
#include<algorithm>
#include<vector>

// Struct to store a set of histograms for a given variable. It stores histograms for sequential cutflows.
// cutBit option allows to store a histogram for a specific cut that is satisfied or not while all the others are.
struct histogramContainer
{
    std::vector<TH1F> m_histos;
    int m_nBins{};
    double m_xMin{};
    double m_xMax{};
    std::string m_baseName{""};
    int m_numberHistos{};
    std::string m_description{""};
    std::string m_cutBit{""};
    std::vector<std::string> m_cutLabels{""};
    bool m_relevantCut{false};
    int m_relevantCutIndex{-1};

    // Default constructor.
    histogramContainer() = default;
    // Copy constructor.
    histogramContainer(const histogramContainer& other) = default;
    // Copy assignment operator.
    histogramContainer& operator=(const histogramContainer& other)
    {
        if (this != &other)
        {
            m_histos = other.m_histos;
            m_nBins = other.m_nBins;
            m_xMin = other.m_xMin;
            m_xMax = other.m_xMax;
            m_baseName = other.m_baseName;
            m_numberHistos = other.m_numberHistos;
            m_description = other.m_description;
            m_cutBit = other.m_cutBit;
            m_cutLabels = other.m_cutLabels;
            m_relevantCut = other.m_relevantCut;
            m_relevantCutIndex = other.m_relevantCutIndex;
        }
        return *this;
    }


    // Constructor for a set of histograms with a defined cutflow.
    histogramContainer(const std::string& baseName, const std::string& description,
    int nBins, double xMin, double xMax, 
    const std::vector<std::string>& cutLabels, const std::string& cutBit = "") : 
    m_baseName{baseName}, m_nBins{nBins}, m_xMin{xMin}, m_xMax{xMax}, m_description{description}, m_cutLabels{cutLabels}, m_cutBit{cutBit}
    {
        // If a histogram has a m_cutBit and it is on the m_cutLabels list, then it is relevant.
        m_relevantCut = !m_cutBit.empty() && ( std::find(m_cutLabels.begin(),m_cutLabels.end(), m_cutBit) !=  m_cutLabels.end()); // Produce a histogram of a cut passed or not while all the others are.
        if (m_relevantCut)
        {
            auto it = std::find(m_cutLabels.begin(),m_cutLabels.end(),m_cutBit);
            m_relevantCutIndex = it-m_cutLabels.begin();
        }

        // Book the histograms.
        m_numberHistos = m_relevantCut ? cutLabels.size()+1 : cutLabels.size(); // Book one more histogram if it is a relevant cut - for the cut-agnostic region.
        std::string name{m_baseName};
        for (int i{0}; i < m_numberHistos; i++)
        {
            if (m_relevantCut)
            {
                m_histos.emplace_back(TH1F(name.c_str(),m_description.c_str(),m_nBins,m_xMin,m_xMax));
                if (i != m_numberHistos-1){name = name +"_" + cutLabels[i];}
                
            } else { // If it is not a relevant cut, then the histograms are created in a sequential way.
                name = name +"_" + cutLabels[i];
                m_histos.emplace_back(TH1F(name.c_str(),m_description.c_str(),m_nBins,m_xMin,m_xMax));
            }
            
        }
    }
    // Filling function : it fills all the histograms all at once taking into account the results passed by a vector of bits.
    void Fill(double value, double weight, const std::vector<int>& cutBits)
    {   
        //First check that the size of the passed cutBits is consistent with the number of cutLabels.
        if (cutBits.size() != m_cutLabels.size())
        {
            g_LOG(LogLevel::ERROR, "The size of the cuts vector passed is not consistent with the definition in Analysis.h");
            g_LOG(LogLevel::ERROR, "Bad histogram: " , m_baseName);
            exit(1);
        }
        int numberPassedCuts{cutBits[0]};
        if (!m_relevantCut) // For non-relevant cuts, fill the histograms sequentially.
        {
            for (int i{0}; i < m_numberHistos; i++)
            {
                if (cutBits[i] == 1) m_histos.at(i).Fill(value,weight);
                else break;
            }
        } else {
            size_t sum{0};
            for(auto &j : cutBits){sum=sum+j;}
            bool passedAllCuts = (sum == cutBits.size());
            bool passedRelevantCut = cutBits.at(m_relevantCutIndex) == 1 ? true : false;
            bool passedAllCutsButRelevantCut = (sum == cutBits.size()-1) && !passedRelevantCut;
            if (passedAllCutsButRelevantCut || passedAllCuts)
            {
                m_histos.at(0).Fill(value,weight);
            }
            for (int i{1}; i < m_numberHistos; i++)
            {
                if (cutBits[i-1] == 1) m_histos.at(i).Fill(value,weight);
                else break;
            }
        }
        
    }
    // Write all histograms to the current directory.
    void Write()
    {
        for (int i{0}; i < m_numberHistos; i++)
        {
            m_histos.at(i).Write();
        }
    }
    // Clean memory on destruction.
    ~histogramContainer() = default;
};

#endif