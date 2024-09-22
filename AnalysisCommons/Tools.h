// Header file with common tools used in analysis.
#pragma once
#include <vector>
#include <TMVA/Reader.h>
#include <sstream>
#include <string>
// Error message with colors!
const char* g_ERROR_MESSAGE = "\033[1;31mERROR:\033[0m";
const char* g_DEBUG_MESSAGE = "\033[1;94mDEBUG:\033[0m";
const char* g_INFO_MESSAGE = "\033[1;92mINFO:\033[0m";

// Enum for log levels.
enum LogLevel {
    ERROR = 1,
    INFO,
    DEBUG,
};

// Class for a logger object.
class Logger {
    public: 
        // Constructor
        Logger(LogLevel level) {
            m_logLevel = level;
        }

        // Destructor
        ~Logger() {}

        static const char* getLogMessage(LogLevel level){
            const char* logMessage = nullptr;
            if (level == LogLevel::INFO) {
                logMessage = g_INFO_MESSAGE;
            } else if (level == LogLevel::DEBUG) {
                logMessage = g_DEBUG_MESSAGE;
            } else if (level == LogLevel::ERROR) {
                logMessage = g_ERROR_MESSAGE;
            }
            return logMessage;
        }

        LogLevel getLogLevel() {
            return m_logLevel;
        }

        // Functions to print the log message.
        template <typename T>
        void operator () (LogLevel level, const T& message) {
            if (level <= getLogLevel()) std::cout << getLogMessage(level) << " " << message << std::endl;
        }

        template <typename T, typename V>
        void operator () (LogLevel level, const T& message1, const V& message2) {
            if (level <= getLogLevel()) std::cout << getLogMessage(level) << " " << message1 << message2 << std::endl;
        }

    private:
        LogLevel m_logLevel = LogLevel::ERROR;
};


Logger g_LOG = Logger(LogLevel::INFO);

// Function to split a string by a delimiter and return a vector of strings.
// Like Python's split function.
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Run numbers
const int run2015Begin = 276262;
const int run2015End   = 284484;

const int run2016Begin = 297730;
const int run2016End   = 311481;

const int run2017Begin = 323427;
const int run2017End   = 341649;

const int run2018Begin = 341649;
const int run2018End   = 364292;


// Class to manage the BDT
class VBFBDT {
  public:
    VBFBDT(const std::string& weightsFilePath) {
        m_reader = new TMVA::Reader("Silent");
        m_reader->AddVariable("mjj",&m_bdt_mjj);
        m_reader->AddVariable("deltaRapidity",&m_bdt_drap);
        m_reader->AddVariable("ptBalance",&m_bdt_ptbal);
        m_reader->AddVariable("zCentrality",&m_bdt_zcen);
        m_reader->AddVariable("omega",&m_bdt_omega);
        //reader->AddVariable("transverseMassLep",&bdt_transmasslep);
        m_reader->AddVariable("transverseRecoMassVariable",&m_bdt_transmasslep); // For transverse-reco mass ratio
        m_reader->AddSpectator("eventNumber", &m_bdt_eventNumber); // For deterministic split
        m_reader->BookMVA("VBF_BDT", weightsFilePath.c_str());
    }

    ~VBFBDT() {
        delete m_reader;
    }

    void update(float mjj, float drap, float ptbal, float zcen, float omega, float transmasslep, float eventNumber) {
        m_bdt_mjj = mjj;
        m_bdt_drap = drap;
        m_bdt_ptbal = ptbal;
        m_bdt_zcen = zcen;
        m_bdt_omega = omega;
        m_bdt_transmasslep = transmasslep;
        m_bdt_eventNumber = eventNumber;
    }

    double evaluate() {
        double bdtScore = m_reader->EvaluateMVA("VBF_BDT");
        reset();
        return bdtScore;
    }

    void reset() {
        m_bdt_mjj = 0;
        m_bdt_drap = 0;
        m_bdt_ptbal = 0;
        m_bdt_zcen = 0;
        m_bdt_omega = 0;
        m_bdt_transmasslep = 0;
        m_bdt_eventNumber = 0;
    }

  private:
    TMVA::Reader* m_reader;
    float m_bdt_mjj;
    float m_bdt_drap;
    float m_bdt_ptbal;
    float m_bdt_zcen;
    float m_bdt_omega;
    float m_bdt_transmasslep;
    float m_bdt_eventNumber;

};