// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <map>
#include <string>

#include "conjugator.hpp"
#include "verb.db.hpp"


// This panel displays all forms of a verb in a specified tense.
class VerbViewPanel : public wxPanel {
    public:
        // Construct a new VerbViewPanel, specifying the tense as int.
        VerbViewPanel(wxWindow* parent, wxWindowID id, const verbDB::Verb* verb, const cjgt::Tense*);

        // Reset the verb of the verb view panel.
        void set_verb(const verbDB::Verb* verb);

    private:
        wxBoxSizer* sizer;

        const verbDB::Verb* verb;
        const cjgt::Tense* tense;
        std::wstring tense_string;
        std::wstring infinitive_string;

        wxStaticText* label_title;
        wxStaticText* label_infinitive;
        std::map<std::wstring, wxStaticText*> labels_forms;
};
