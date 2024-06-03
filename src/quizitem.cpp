// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "quizitem.hpp"


QuizItem::QuizItem(wxWindow* parent, wxFlexGridSizer* sizer, const cjgt::QuizData& data, const bool& translate) {
    this->data = data;
    this->sizer = sizer;
    this->parent = parent;

    // Don't show a person if the question is prompting for a participe present form.
    if (*data.person == L"") {
        questionString = *data.verb_name + L": " + data.tense->name;
    } else {
        questionString = *data.verb_name + L": " + data.tense->name + L" – " + *data.person;
    }

    question = new wxStaticText(parent, 
        wxID_ANY, 
        wxString(questionString)
    );

    // Create a text control with a minimum width of 150.
    textCtrl = new wxTextCtrl(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(150, wxDefaultSize.GetY()));

    solution = new wxStaticText(parent, wxID_ANY, wxEmptyString);

    sizer->Add(
        question,
        0,
        wxALIGN_CENTER_VERTICAL,
        0
    );

    sizer->Add(
        textCtrl,
        0,
        wxEXPAND | wxALIGN_CENTER_VERTICAL,
        0
    );

   sizer->Add(
        solution,
        0,
        wxALIGN_CENTER_VERTICAL | wxALIGN_LEFT,
        0
    );
}

void QuizItem::SetFocus() {
    textCtrl->SetFocus();
}

void QuizItem::setQuizData(const cjgt::QuizData& data, const bool& translate) {
    this->data = data;

    std::wstring infinitif;

    if (*data.person == L"") {
        questionString = *data.verb_name + L": " + data.tense->name;
    } else {
        questionString = *data.verb_name + L": " + data.tense->name + L" – " + *data.person;
    }

    // Set the text colour back to default.
    textCtrl->SetForegroundColour(wxNullColour);

    textCtrl->Clear();

    solution->SetLabelText(wxEmptyString);

    question->SetLabelText(questionString);
}

bool QuizItem::evaluate() {
    bool correct;
    std::wstring textCtrlString = std::wstring(textCtrl->GetValue().wchar_str());

    correct = textCtrlString == *this->data.form;

    if (cjgt::strip(textCtrlString).empty()) {
        textCtrl->SetForegroundColour(wxNullColour);
    }
    else if (correct) {
        textCtrl->SetForegroundColour(*wxGREEN);
    } else {
        textCtrl->SetForegroundColour(*wxRED);
    }

    textCtrl->Refresh();

    return correct;
}

void QuizItem::showSolution() {
    std::wstring solutionStr;

    solution->SetLabelText(wxString(*this->data.form));
}
