// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "verbview.hpp"


VerbView::VerbView(wxWindow* parent, wxWindowID id, const verbDB::Verb &verb) : wxPanel(parent, id) {
    this->verb = verb;
    
    sizer = new wxBoxSizer(wxVERTICAL);
    
    tensebook = new wxChoicebook(this, wxID_ANY);

    // Create a verb view panel for each tense from present to conditionnel and add it to the tensebook.
    for (int tense = verbDB::Tense::present; tense <= verbDB::Tense::conditionnel; tense++) {
        pages.insert({tense, new VerbViewPanel(tensebook, wxID_ANY, verb, tense)});
        tensebook->InsertPage(tense - verbDB::Tense::present, pages.at(tense), wxString(cjgt::getTense(tense)));
    }
    
    sizer->Add(tensebook, 0, wxEXPAND | wxALL, 10);

    this->SetSizerAndFit(sizer);

}

void VerbView::setVerb(const verbDB::Verb &inputVerb) {
    verb = inputVerb;
    
    for (int tense = verbDB::Tense::present; tense <= verbDB::Tense::conditionnel; tense ++) {
        pages.at(tense)->setVerb(verb);
    }
    
    sizer->SetSizeHints(this);
}
