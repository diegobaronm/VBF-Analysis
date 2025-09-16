# pragma once

#include <memory>

#define DECLARE_SYS_HISTOGRAMS(systematic_name_begin, systematic_name_end) \
  std::unique_ptr<TH1F> h_mass_jj_##systematic_name_begin##_1down_##systematic_name_end; \
  std::unique_ptr<TH1F> h_mass_jj_##systematic_name_begin##_1up_##systematic_name_end; \

#define DEFINE_SYS_HISTOGRAMS(systematic_name_begin, systematic_name_end) \
  h_mass_jj_##systematic_name_begin##_1down_##systematic_name_end = std::make_unique<TH1F>("mass_jj_"#systematic_name_begin"_1down_"#systematic_name_end,"Invariant mass di-jet system",5000,0,5000); \
  h_mass_jj_##systematic_name_begin##_1up_##systematic_name_end = std::make_unique<TH1F>("mass_jj_"#systematic_name_begin"_1up_"#systematic_name_end,"Invariant mass di-jet system",5000,0,5000); \

#define FILL_SYS_HISTOGRAMS(systematic_name_begin, systematic_name_end, nominal) \
  h_mass_jj_##systematic_name_begin##_1down_##systematic_name_end->Fill(mjj, weight * systematic_name_begin##_1down_##systematic_name_end / nominal); \
  h_mass_jj_##systematic_name_begin##_1up_##systematic_name_end->Fill(mjj, weight * systematic_name_begin##_1up_##systematic_name_end / nominal); \

#define FILL_SYS_TRIGGER_HISTOGRAMS(systematic_name_begin, systematic_name_end, trigger1, trigger2, nominal) \
  h_mass_jj_##systematic_name_begin##_1down_##systematic_name_end->Fill(mjj, weight * (systematic_name_begin##_1down_##trigger1 + systematic_name_begin##_1down_##trigger2)/ nominal); \
  h_mass_jj_##systematic_name_begin##_1up_##systematic_name_end->Fill(mjj, weight * (systematic_name_begin##_1up_##trigger1 + systematic_name_begin##_1up_##trigger2)/ nominal); \

#define WRITE_SYS_HISTOGRAMS(systematic_name_begin, systematic_name_end) \
  h_mass_jj_##systematic_name_begin##_1down_##systematic_name_end->Write(); \
  h_mass_jj_##systematic_name_begin##_1up_##systematic_name_end->Write();

#define INSERT_SYS_THEORY_MAP(theory_map, weight) \
  theory_map[#weight] = weight;

