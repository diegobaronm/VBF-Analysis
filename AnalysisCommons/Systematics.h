# pragma once

#include <memory>

#define DECLARE_SYS_HISTOGRAMS(systematic_name_begin, systematic_name_end) \
  std::unique_ptr<TH1F> h_mass_jj_##systematic_name_begin##_1down_##systematic_name_end; \
  std::unique_ptr<TH1F> h_mass_jj_##systematic_name_begin##_1up_##systematic_name_end; \

#define DECLARE_SYS_HISTOGRAMS_NOEND(systematic_name_begin) \
  std::unique_ptr<TH1F> h_mass_jj_##systematic_name_begin##_1down; \
  std::unique_ptr<TH1F> h_mass_jj_##systematic_name_begin##_1up; \

#define DEFINE_SYS_HISTOGRAMS(systematic_name_begin, systematic_name_end) \
  h_mass_jj_##systematic_name_begin##_1down_##systematic_name_end = std::make_unique<TH1F>("mass_jj_"#systematic_name_begin"_1down_"#systematic_name_end,"Invariant mass di-jet system",5000,0,5000); \
  h_mass_jj_##systematic_name_begin##_1up_##systematic_name_end = std::make_unique<TH1F>("mass_jj_"#systematic_name_begin"_1up_"#systematic_name_end,"Invariant mass di-jet system",5000,0,5000); \

#define DEFINE_SYS_HISTOGRAMS_NOEND(systematic_name_begin) \
  h_mass_jj_##systematic_name_begin##_1down = std::make_unique<TH1F>("mass_jj_"#systematic_name_begin"_1down","Invariant mass di-jet system",5000,0,5000); \
  h_mass_jj_##systematic_name_begin##_1up = std::make_unique<TH1F>("mass_jj_"#systematic_name_begin"_1up","Invariant mass di-jet system",5000,0,5000); \

#define FILL_SYS_HISTOGRAMS(systematic_name_begin, systematic_name_end, nominal) \
  h_mass_jj_##systematic_name_begin##_1down_##systematic_name_end->Fill(mjj, weight * systematic_name_begin##_1down_##systematic_name_end / nominal); \
  h_mass_jj_##systematic_name_begin##_1up_##systematic_name_end->Fill(mjj, weight * systematic_name_begin##_1up_##systematic_name_end / nominal); \

#define FILL_SYS_HISTOGRAMS_NOEND(systematic_name_begin, nominal) \
  h_mass_jj_##systematic_name_begin##_1down->Fill(mjj, weight * systematic_name_begin##_1down / nominal); \
  h_mass_jj_##systematic_name_begin##_1up->Fill(mjj, weight * systematic_name_begin##_1up / nominal); \

#define FILL_SYS_MUON_TRIGGER_HISTOGRAMS(systematic_name_begin, systematic_name_end, trigger, nominal) \
  h_mass_jj_##systematic_name_begin##_1down_##systematic_name_end->Fill(mjj, weight * systematic_name_begin##_1down_##trigger / nominal); \
  h_mass_jj_##systematic_name_begin##_1up_##systematic_name_end->Fill(mjj, weight * systematic_name_begin##_1up_##trigger / nominal); \

#define FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS(systematic_name_begin, systematic_name_end, muon_x, trigger, nominal) \
  h_mass_jj_##systematic_name_begin##_1down_##systematic_name_end->Fill(mjj, weight * muon_x##_1down_##trigger / nominal); \
  h_mass_jj_##systematic_name_begin##_1up_##systematic_name_end->Fill(mjj, weight * muon_x##_1up_##trigger / nominal); \

#define FILL_SYS_DI_MUON_TRIGGER_HISTOGRAMS_DUMMY(systematic_name_begin, systematic_name_end) \
  h_mass_jj_##systematic_name_begin##_1down_##systematic_name_end->Fill(mjj, weight ); \
  h_mass_jj_##systematic_name_begin##_1up_##systematic_name_end->Fill(mjj, weight ); \

#define FILL_SYS_2LEP_HISTOGRAMS(systematic_name_begin, systematic_name_end, nominal1, nominal2) \
  h_mass_jj_muon_##systematic_name_begin##_1down_##systematic_name_end->Fill(mjj, weight * ( muon_0_##systematic_name_begin##_1down_##systematic_name_end * muon_1_##systematic_name_begin##_1down_##systematic_name_end ) / (nominal1 * nominal2)); \
  h_mass_jj_muon_##systematic_name_begin##_1up_##systematic_name_end->Fill(mjj, weight * ( muon_0_##systematic_name_begin##_1up_##systematic_name_end * muon_1_##systematic_name_begin##_1up_##systematic_name_end ) / (nominal1 * nominal2)); \

#define WRITE_SYS_HISTOGRAMS(systematic_name_begin, systematic_name_end) \
  h_mass_jj_##systematic_name_begin##_1down_##systematic_name_end->Write(); \
  h_mass_jj_##systematic_name_begin##_1up_##systematic_name_end->Write();

#define WRITE_SYS_HISTOGRAMS_NOEND(systematic_name_begin) \
  h_mass_jj_##systematic_name_begin##_1down->Write(); \
  h_mass_jj_##systematic_name_begin##_1up->Write();

#define INSERT_SYS_THEORY_MAP(theory_map, weight) \
  theory_map[#weight] = weight;

