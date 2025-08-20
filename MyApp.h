#pragma once

#include <wx/glcanvas.h>
#include <wx/wx.h>
#include <wx/hyperlink.h>
#include <wx/aboutdlg.h>
#include <wx/spinctrl.h>


#include <glm/glm.hpp>


// the rendering context used by all GL canvases
class TestGLContext : public wxGLContext
{
public:
	/*TestGLContext(wxGLCanvas* canvas);

	// render the cube showing it at given angles
	void DrawRotatedCube(float xangle = 0, float yangle = 0);

	void DrawRotatedCube(glm::fquat q);

	void DrawRotatedCube(float xangle = 0, float yangle = 0, float zangle = 0);*/

private:
	// textures for the cube faces
	GLuint m_textures[6];
};


class TestGLCanvas : public wxGLCanvas
{
public:
	TestGLCanvas(wxWindow* parent, int* attribList = NULL);

	// angles of rotation around x- and y- axis
	float m_xangle;
	float m_yangle;

private:
	void OnPaint(wxPaintEvent& event);
	void OnKeyDown(wxKeyEvent& event);
	void OnSpinTimer(wxTimerEvent& WXUNUSED(event));



	wxTimer m_spinTimer;
	bool m_useStereo,
		m_stereoWarningAlreadyDisplayed;

	wxDECLARE_EVENT_TABLE();
};

enum
{
	NEW_STEREO_WINDOW = wxID_HIGHEST + 1
};


// Define a new application type
class MyApp : public wxApp
{
public:
	MyApp() {};

	// virtual wxApp methods
	virtual bool OnInit();

	virtual int OnExit();

	void onIdle(wxIdleEvent& evt);

	// Returns the shared context used by all frames and sets it as current for
	// the given canvas.
	TestGLContext& GetContext(wxGLCanvas* canvas, bool useStereo);

private:
	// the GL context we use for all our mono rendering windows
	TestGLContext* m_glContext;
	// the GL context we use for all our stereo rendering windows
	TestGLContext* m_glStereoContext;

	wxTimer m_myTimer;
};




// Define a new frame type
class MainFrame : public wxFrame
{
public:

	wxApp* parent;


	wxCheckBox* CB1;
	wxCheckBox* CB2;
	wxCheckBox* CB3;
	wxCheckBox* CB4;
	wxCheckBox* CB5;
	wxCheckBox* CB6;
	wxCheckBox* CB7;
	wxCheckBox* CB8;
	wxCheckBox* CB9;
	wxCheckBox* CB10;
	wxCheckBox* CB11;
	wxCheckBox* CB12;
	wxCheckBox* CB13;
	wxCheckBox* CB14;
	wxCheckBox* CB15;
	wxCheckBox* CB16;
	// added for run unlocks other
	wxCheckBox* CB97;
	// added these for reverse rx, ry
	wxCheckBox* CB98;
	wxCheckBox* CB99;
	// trying to flip right and left sticks
	wxCheckBox* flipSticksBox;



	wxStaticText* st1;
	wxStaticText* st2;
	wxStaticText* st3;
	wxStaticText* st4;

	wxSlider* slider1;
	wxSlider* slider2;
	wxSlider* slider3;
	wxStaticText* slider1Text;
	wxStaticText* slider2Text;
	wxStaticText* slider3Text;

	// We want to add new sliders for gyro offsets
	wxSpinCtrl* pitchCtrl;
	wxSpinCtrl* rollCtrl;
	wxSpinCtrl* yawCtrl;

	wxSpinCtrl* heavyPressMinCtrl;
	wxSpinCtrl* heavyPressMaxCtrl;
	wxSpinCtrl* lightPressMinCtrl;
	wxSpinCtrl* lightPressMaxCtrl;
	wxSpinCtrl* deadZoneMinCtrl;
	wxSpinCtrl* deadZoneMaxCtrl;
	wxSpinCtrl* heavyPullMinCtrl;
	wxSpinCtrl* heavyPullMaxCtrl;
	wxSpinCtrl* lightPullMinCtrl;
	wxSpinCtrl* lightPullMaxCtrl;

	wxStaticText* heavyPressMaxText;
	wxStaticText* heavyPressMinText;
	wxStaticText* lightPressMaxText;
	wxStaticText* lightPressMinText;
	wxStaticText* deadZoneMaxText;
	wxStaticText* deadZoneMinText;
	wxStaticText* heavyPullMaxText;
	wxStaticText* heavyPullMinText;
	wxStaticText* lightPullMaxText;
	wxStaticText* lightPullMinText;
	wxButton* updatePressRangesButton;
	wxButton* loadPressRangesButton;
	wxButton* savePressRangesButton;

	wxStaticText* pitchCtrlText;
	wxStaticText* rollCtrlText;
	wxStaticText* yawCtrlText;
	//

	wxButton* startButton;
	wxButton* quitButton;
	wxButton* updateButton;
	wxButton* donateButton;


	MainFrame();

	void onStart(wxCommandEvent&);
	void onQuit(wxCommandEvent&);

	void onQuit2(wxCloseEvent&);

	//void onUpdate(wxCommandEvent&);
	void onDonate(wxCommandEvent&);

	void toggleCombine(wxCommandEvent&);

	void toggleGyro(wxCommandEvent&);
	void toggleSquatSlowsMouse(wxCommandEvent&);
	void toggleMario(wxCommandEvent&);

	void toggleReverseX(wxCommandEvent&);
	void toggleReverseY(wxCommandEvent&);

	void toggleReverseLX(wxCommandEvent&);
	void toggleReverseLY(wxCommandEvent&);
	void toggleReverseRX(wxCommandEvent&);
	void toggleReverseRY(wxCommandEvent&);


	void togglePreferLeftJoyCon(wxCommandEvent&);
	void toggleQuickToggleGyro(wxCommandEvent&);
	void toggleInvertQuickToggle(wxCommandEvent&);
	void toggleDolphinPointerMode(wxCommandEvent&);

	void toggleRunpressesbutton(wxCommandEvent&);
	void toggleRingconFix(wxCommandEvent&);

	void toggleRunUnlocksGyro(wxCommandEvent&);
	void toggleRunUnlocksOther(wxCommandEvent&);

	void setGyroSensitivityX(wxCommandEvent&);
	void setGyroSensitivityY(wxCommandEvent&);
	void setRingconFix(wxCommandEvent&);
	// flip sticks
	void toggleFlipSticks(wxCommandEvent&);

	// We're adding the ability to offset these so people can hold it however they want
	void setGyroOffsetRoll(wxCommandEvent&);
	void setGyroOffsetPitch(wxCommandEvent&);
	void setGyroOffsetYaw(wxCommandEvent&);


	void toggleRingconFullRH(wxCommandEvent&);
	void toggleRingconToAnalog(wxCommandEvent&);

	void updatePressRanges(wxCommandEvent&);
	void loadPressRanges(wxCommandEvent&);
	void savePressRanges(wxCommandEvent&);
	//void checkForUpdate();

};






// Define a new frame type
class MyFrame : public wxFrame
{
public:
	MyFrame(bool stereoWindow = false);

private:
	void OnClose(wxCommandEvent& event);
	void OnNewWindow(wxCommandEvent& event);
	void OnNewStereoWindow(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};




