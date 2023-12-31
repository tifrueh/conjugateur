// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include <vector>

#include "conjugateur.hpp"
#include "quizitem.hpp"

class TopPanel : public wxPanel {
    public:
        explicit TopPanel(wxWindow* parent);
        std::vector<cjgt::VerbForm> GetVerbForms(const int& count);
        void ResetFocus();
        void GenerateQuiz();
        void Check();
        void ShowSolutions();
        void SelectAllVerbs();
        void SelectAllTenses();
        void UnselectAll();

    private:
        int quizItemCount;
        wxBoxSizer* topsizer = nullptr;
        wxStaticBoxSizer* formSelectionSizer = nullptr;
        wxStaticBoxSizer* quizBoxSizer = nullptr;
        wxFlexGridSizer* quizSizer = nullptr;
        wxStaticText* verbTypeTitle = nullptr;
        wxCheckBox* checkBoxER = nullptr;
        wxCheckBox* checkBoxIR = nullptr;
        wxCheckBox* checkBoxOIR = nullptr;
        wxCheckBox* checkBoxRE = nullptr;
        wxStaticText* tenseTitle = nullptr;
        wxCheckBox* checkBoxParticipePresent = nullptr;
        wxCheckBox* checkBoxPresent = nullptr;
        wxCheckBox* checkBoxImparfait = nullptr;
        wxCheckBox* checkBoxFutur = nullptr;
        wxCheckBox* checkBoxPasseCompose = nullptr;
        wxCheckBox* checkBoxPlusQueParfait = nullptr;
        wxCheckBox* checkBoxSubjonctif = nullptr;
        wxCheckBox* checkBoxConditionnel = nullptr;
        wxBoxSizer* buttonSizer = nullptr;
        wxButton* okayButton = nullptr;
        wxButton* checkButton = nullptr;
        wxButton* solutionButton = nullptr;
        std::vector<QuizItem*> quizItems;
};
