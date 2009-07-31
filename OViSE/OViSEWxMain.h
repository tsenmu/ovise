/***************************************************************
 * Name:      OViSEWxMain.h
 * Purpose:   Defines Application Frame
 * Author:    Alexander Kasper (akasper@ira.uka.de)
 * Created:   2008-09-11
 * Copyright: Alexander Kasper (http://i61www.ira.uka.de/users/akasper)
 * License:
 **************************************************************/

#ifndef OVISEWXMAIN_H
#define OVISEWXMAIN_H



#include "OViSEWxApp.h"

#include <wx/aui/aui.h>
#include <wx/propgrid/propgrid.h>
#include <wx/tokenzr.h>
#include <wx/aboutdlg.h>
#include <wx/treectrl.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/imaglist.h>

#include "GUIFrame.h"
#include "wxOgreRenderWindow.h"
#include "OViSESceneHandling.h"
#include "OViSELogListener.h"
#include "OViSEAddMeshDialog.h"
#include "OViSESceneTree.h"

#ifndef OVISE_EXPORT_MESHES_DIALOG_USED
#define OVISE_EXPORT_MESHES_DIALOG_USED
#include "OViSEExportMeshesDialog.h"
#endif

#ifndef OVISE_ATTACH_SCENE_DIALOG_USED
#define OVISE_ATTACH_SCENE_DIALOG_USED
#include "OViSEAttachSceneDialog.h"
#endif

enum
{
    WINDOW_MainRender = wxID_HIGHEST + 1,
	PGID,
	SCENETREE
};

/** Mainwindow of the application.
 * @todo Documentation!
 */
class OViSEWxFrame: public GUIFrame
{
    public:
		OViSEWxFrame(wxFrame *frame, Ogre::Root *ogreRoot);
        ~OViSEWxFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
		virtual void OnAddView(wxCommandEvent& event);
		virtual void OnAdditionalViewClose(wxCloseEvent& event);
		virtual void OnSaveScreenToFile(wxCommandEvent& event);
		virtual void OnSceneAddMesh(wxCommandEvent& event);
		virtual void OnAddMeshDialogClose(wxCloseEvent& event);
		virtual void OnViewClick(wxMouseEvent& event);
		virtual void OnPropertyChange(wxPropertyGridEvent& event);
		virtual void OnMenuDeleteMeshes( wxCommandEvent& event );
		virtual void OnImportScenePrototype( wxCommandEvent& event);
		virtual void OnExportScenePrototype( wxCommandEvent& event );
		virtual void OnAttachNewScene( wxCommandEvent& event );
		virtual void OnLoadPointCloud( wxCommandEvent& event );
		virtual void OnShowSceneStructure( wxCommandEvent& event);
		virtual void OnDynamicShadowsChange(wxCommandEvent& event);
		virtual void OnTestStuff( wxCommandEvent& event );
		virtual void OnStartStopFrameListeners(wxCommandEvent& event);

		void setObjectProperties(Ogre::MovableObject *object);
		void clearObjectProperties();
		void deleteMeshes();

    protected:
		void finishOgreInitialization();

		void setupObjectProperties();

		void loadSceneTreeImageList(wxImageList *list);

		Ogre::Root *mRoot;

        wxOgreRenderWindow *mMainRenderWin;

		wxListBox *logBox;
		//wxSplitterWindow *mSplitter;
		//wxSplitterWindow *mSecondSplitter, *mThirdSplitter;

		wxAuiManager *mWindowManager;

		OViSESceneTree *mSceneTree;

		wxPropertyGrid *mObjectProperties;
		
		Ogre::SceneManager *mSceneMgr;
        Ogre::Camera *mCam;

		std::map<std::string, Ogre::Camera*> mAdditionalCameras;
		std::map<std::string, wxFrame*> mViewWindows;

        OViSESceneHandling *mSceneHdlr;

		OViSELogListener *mLogBoxListener;

		OViSEAddMeshDialog *mAddMeshDialog;
};

#endif // OVISEWXMAIN_H
