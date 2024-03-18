// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include "id.hpp"
#include "checkerpanel.hpp"

// The most top-level frame of the checker window.
class CheckerFrame : public wxFrame {
    public:
        // Construct a new checker frame.
        CheckerFrame(wxWindow* parent, const wxWindowID& winID, const wxString& title);

    private:
        wxBoxSizer* topSizer;
        CheckerPanel* checkerPanel;
};
