///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version May  4 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "MainFrameBase.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	mbar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, idMenuQuit, wxString( wxT("&Quit") ) + wxT('\t') + wxT("Alt+F4"), wxT("Quit the application"), wxITEM_NORMAL );
	fileMenu->Append( menuFileQuit );
	
	mbar->Append( fileMenu, wxT("&File") ); 
	
	view = new wxMenu();
	wxMenuItem* showStructure;
	showStructure = new wxMenuItem( view, ID_SHOW_STRUCTURE, wxString( wxT("Show Structure") ) + wxT('\t') + wxT("M"), wxT("Show Scene Structure"), wxITEM_NORMAL );
	view->Append( showStructure );
	
	wxMenuItem* saveScreenshotToFile;
	saveScreenshotToFile = new wxMenuItem( view, ID_SAVE_SCREENSHOT_TO_FILE, wxString( wxT("Save Screenshot to File...") ) , wxT("Saves a screenshot of the view to a file specified by the user."), wxITEM_NORMAL );
	view->Append( saveScreenshotToFile );
	
	wxMenuItem* dynamicShadows;
	dynamicShadows = new wxMenuItem( view, ID_DYNAMIC_SHADOWS, wxString( wxT("Dynamic Shadows") ) , wxEmptyString, wxITEM_CHECK );
	view->Append( dynamicShadows );
	
	displayMode = new wxMenu();
	points = new wxMenuItem( displayMode, ID_POINTS, wxString( wxT("Points") ) , wxEmptyString, wxITEM_RADIO );
	displayMode->Append( points );
	
	wireframe = new wxMenuItem( displayMode, ID_WIREFRAME, wxString( wxT("Wireframe") ) , wxEmptyString, wxITEM_RADIO );
	displayMode->Append( wireframe );
	
	solid = new wxMenuItem( displayMode, ID_SOLID, wxString( wxT("Solid") ) , wxEmptyString, wxITEM_RADIO );
	displayMode->Append( solid );
	solid->Check( true );
	
	view->Append( -1, wxT("Display Mode"), displayMode );
	
	mbar->Append( view, wxT("View") ); 
	
	scene = new wxMenu();
	wxMenuItem* addMesh;
	addMesh = new wxMenuItem( scene, ID_ADD_MESH, wxString( wxT("Add Mesh") ) + wxT('\t') + wxT("I"), wxT("Add a new mesh to the scene"), wxITEM_NORMAL );
	scene->Append( addMesh );
	
	wxMenuItem* deleteMeshes;
	deleteMeshes = new wxMenuItem( scene, ID_DELETE_MESHES, wxString( wxT("Delete Mesh(es)") ) + wxT('\t') + wxT("X"), wxT("Remove selected meshes from scene"), wxITEM_NORMAL );
	scene->Append( deleteMeshes );
	
	wxMenuItem* m_separator1;
	m_separator1 = scene->AppendSeparator();
	
	wxMenuItem* OpenPrototypeManagement;
	OpenPrototypeManagement = new wxMenuItem( scene, ID_OPEN_PROTOTYPE_MANAGEMENT, wxString( wxT("Manage Prototypes ( dotScene )") ) , wxT("Opens a dialog, which allows management of (dotScene) prototypes."), wxITEM_NORMAL );
	scene->Append( OpenPrototypeManagement );
	
	wxMenuItem* m_separator2;
	m_separator2 = scene->AppendSeparator();
	
	wxMenuItem* loadPointcloud;
	loadPointcloud = new wxMenuItem( scene, ID_LOAD_POINTCLOUD, wxString( wxT("Load Pointcloud") ) , wxEmptyString, wxITEM_NORMAL );
	scene->Append( loadPointcloud );
	
	mbar->Append( scene, wxT("Scene") ); 
	
	helpMenu = new wxMenu();
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( wxT("&About") ) + wxT('\t') + wxT("F1"), wxT("Show info about this application"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );
	
	mbar->Append( helpMenu, wxT("&Help") ); 
	
	debug = new wxMenu();
	wxMenuItem* teststuff;
	teststuff = new wxMenuItem( debug, ID_TESTSTUFF, wxString( wxT("TestStuff") ) , wxEmptyString, wxITEM_NORMAL );
	debug->Append( teststuff );
	
	mbar->Append( debug, wxT("Debug") ); 
	
	this->SetMenuBar( mbar );
	
	statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnClose ) );
	this->Connect( idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnQuit ) );
	this->Connect( ID_SHOW_STRUCTURE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnShowSceneStructure ) );
	this->Connect( ID_SAVE_SCREENSHOT_TO_FILE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnSaveScreenToFile ) );
	this->Connect( ID_DYNAMIC_SHADOWS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDynamicShadowsChange ) );
	this->Connect( ID_POINTS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDMPoints ) );
	this->Connect( ID_WIREFRAME, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDMWire ) );
	this->Connect( ID_SOLID, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDMSolid ) );
	this->Connect( ID_ADD_MESH, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnSceneAddMesh ) );
	this->Connect( ID_DELETE_MESHES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuDeleteMeshes ) );
	this->Connect( ID_OPEN_PROTOTYPE_MANAGEMENT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnOpenPrototypeManagement ) );
	this->Connect( ID_LOAD_POINTCLOUD, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnLoadPointCloud ) );
	this->Connect( idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAbout ) );
	this->Connect( ID_TESTSTUFF, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnTestStuff ) );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnClose ) );
	this->Disconnect( idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnQuit ) );
	this->Disconnect( ID_SHOW_STRUCTURE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnShowSceneStructure ) );
	this->Disconnect( ID_SAVE_SCREENSHOT_TO_FILE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnSaveScreenToFile ) );
	this->Disconnect( ID_DYNAMIC_SHADOWS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDynamicShadowsChange ) );
	this->Disconnect( ID_POINTS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDMPoints ) );
	this->Disconnect( ID_WIREFRAME, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDMWire ) );
	this->Disconnect( ID_SOLID, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDMSolid ) );
	this->Disconnect( ID_ADD_MESH, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnSceneAddMesh ) );
	this->Disconnect( ID_DELETE_MESHES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnMenuDeleteMeshes ) );
	this->Disconnect( ID_OPEN_PROTOTYPE_MANAGEMENT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnOpenPrototypeManagement ) );
	this->Disconnect( ID_LOAD_POINTCLOUD, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnLoadPointCloud ) );
	this->Disconnect( idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAbout ) );
	this->Disconnect( ID_TESTSTUFF, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnTestStuff ) );
	
}

AddMeshDialog::AddMeshDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );
	
	ListSizer = new wxBoxSizer( wxHORIZONTAL );
	
	mMeshList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_NEEDED_SB|wxLB_SINGLE|wxLB_SORT ); 
	ListSizer->Add( mMeshList, 1, wxALL|wxEXPAND, 5 );
	
	MainSizer->Add( ListSizer, 4, wxEXPAND, 5 );
	
	wxBoxSizer* buttonSizer;
	buttonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	
	buttonSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	mOkButton = new wxButton( this, wxID_OK, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonSizer->Add( mOkButton, 0, wxALL, 5 );
	
	mApplyButton = new wxButton( this, wxID_APPLY, wxT("Apply"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonSizer->Add( mApplyButton, 0, wxALL, 5 );
	
	mCancelButton = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonSizer->Add( mCancelButton, 0, wxALL, 5 );
	
	MainSizer->Add( buttonSizer, 0, wxEXPAND, 5 );
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( AddMeshDialog::OnCloseDialog ) );
	mMeshList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( AddMeshDialog::OnMeshListSelect ), NULL, this );
	mOkButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMeshDialog::OnOkClick ), NULL, this );
	mApplyButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMeshDialog::OnApplyClick ), NULL, this );
	mCancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMeshDialog::OnCancelClick ), NULL, this );
}

AddMeshDialog::~AddMeshDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( AddMeshDialog::OnCloseDialog ) );
	mMeshList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( AddMeshDialog::OnMeshListSelect ), NULL, this );
	mOkButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMeshDialog::OnOkClick ), NULL, this );
	mApplyButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMeshDialog::OnApplyClick ), NULL, this );
	mCancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddMeshDialog::OnCancelClick ), NULL, this );
	
}

ExportMeshesDialog::ExportMeshesDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* LabelSizer;
	LabelSizer = new wxBoxSizer( wxVERTICAL );
	
	mLabel = new wxStaticText( this, wxID_ANY, wxT("Do you want to export used meshes of scene too?"), wxDefaultPosition, wxDefaultSize, 0 );
	mLabel->Wrap( -1 );
	LabelSizer->Add( mLabel, 0, wxALL, 5 );
	
	
	LabelSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	MainSizer->Add( LabelSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* ButtonSizer;
	ButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	mCancelButton = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( mCancelButton, 0, wxALL, 5 );
	
	
	ButtonSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	mOkButton = new wxButton( this, wxID_ANY, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( mOkButton, 0, wxALL, 5 );
	
	mDeleteButton = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( mDeleteButton, 0, wxALL, 5 );
	
	MainSizer->Add( ButtonSizer, 1, wxEXPAND, 5 );
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ExportMeshesDialog::OnCloseDialog ) );
	mCancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExportMeshesDialog::OnClickCancel ), NULL, this );
	mOkButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExportMeshesDialog::OnClickOk ), NULL, this );
}

ExportMeshesDialog::~ExportMeshesDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( ExportMeshesDialog::OnCloseDialog ) );
	mCancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExportMeshesDialog::OnClickCancel ), NULL, this );
	mOkButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ExportMeshesDialog::OnClickOk ), NULL, this );
	
}

_PrototypeManagementDialog::_PrototypeManagementDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	MainSizer = new wxBoxSizer( wxVERTICAL );
	
	ListBoxSizer = new wxBoxSizer( wxHORIZONTAL );
	
	mPrototypeList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_ALWAYS_SB|wxLB_SORT ); 
	ListBoxSizer->Add( mPrototypeList, 2, wxALL|wxEXPAND, 5 );
	
	MainSizer->Add( ListBoxSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* ButtonSizer;
	ButtonSizer = new wxBoxSizer( wxHORIZONTAL );
	
	mRemoveButton = new wxButton( this, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	mRemoveButton->Enable( false );
	
	ButtonSizer->Add( mRemoveButton, 0, wxALL, 5 );
	
	mImportButton = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( mImportButton, 0, wxALL, 5 );
	
	mExportButton = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxDefaultSize, 0 );
	mExportButton->Enable( false );
	
	ButtonSizer->Add( mExportButton, 0, wxALL, 5 );
	
	mBuildButton = new wxButton( this, wxID_ANY, wxT("Build Prototype"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( mBuildButton, 0, wxALL, 5 );
	
	mAttachButton = new wxButton( this, wxID_ANY, wxT("Attach Prototype"), wxDefaultPosition, wxDefaultSize, 0 );
	mAttachButton->Enable( false );
	
	ButtonSizer->Add( mAttachButton, 0, wxALL, 5 );
	
	mCloseButton = new wxButton( this, wxID_ANY, wxT("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	ButtonSizer->Add( mCloseButton, 1, wxALL, 5 );
	
	MainSizer->Add( ButtonSizer, 0, wxEXPAND, 5 );
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( _PrototypeManagementDialog::OnCloseDialog ) );
	mPrototypeList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( _PrototypeManagementDialog::OnProtoTypeListSelect ), NULL, this );
	mRemoveButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _PrototypeManagementDialog::OnClickRemove ), NULL, this );
	mImportButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _PrototypeManagementDialog::OnClickImport ), NULL, this );
	mExportButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _PrototypeManagementDialog::OnClickExport ), NULL, this );
	mBuildButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _PrototypeManagementDialog::OnClickBuild ), NULL, this );
	mAttachButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _PrototypeManagementDialog::OnClickAttach ), NULL, this );
	mCloseButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _PrototypeManagementDialog::OnClickClose ), NULL, this );
}

_PrototypeManagementDialog::~_PrototypeManagementDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( _PrototypeManagementDialog::OnCloseDialog ) );
	mPrototypeList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( _PrototypeManagementDialog::OnProtoTypeListSelect ), NULL, this );
	mRemoveButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _PrototypeManagementDialog::OnClickRemove ), NULL, this );
	mImportButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _PrototypeManagementDialog::OnClickImport ), NULL, this );
	mExportButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _PrototypeManagementDialog::OnClickExport ), NULL, this );
	mBuildButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _PrototypeManagementDialog::OnClickBuild ), NULL, this );
	mAttachButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _PrototypeManagementDialog::OnClickAttach ), NULL, this );
	mCloseButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( _PrototypeManagementDialog::OnClickClose ), NULL, this );
	
}

PathConfigDialog::PathConfigDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	mMainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* WelcomeSizer;
	WelcomeSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Welcome") ), wxVERTICAL );
	
	wxStaticText* mWelcomeLabel;
	mWelcomeLabel = new wxStaticText( this, wxID_ANY, wxT("You are running OViSE for the first time or it has been moved.\n\nThis application uses resources located at different paths. These paths must be properly configured now. If you have never run this dialog before, the paths are guessed and probably correct as they are. In rare cases, however, it might be necessary to manually adjust them."), wxDefaultPosition, wxDefaultSize, 0 );
	mWelcomeLabel->Wrap( 580 );
	WelcomeSizer->Add( mWelcomeLabel, 0, wxALL, 5 );
	
	mMainSizer->Add( WelcomeSizer, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* CmdPathSizer;
	CmdPathSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Working Directory (Usually, this is where your executable files are located)") ), wxVERTICAL );
	
	mCmdDirPicker = new wxDirPickerCtrl( this, wxID_ANY, wxT("Not configured"), wxT("Select OViSE's CMD folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_DIR_MUST_EXIST );
	CmdPathSizer->Add( mCmdDirPicker, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	mMainSizer->Add( CmdPathSizer, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* BasePathSizer;
	BasePathSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Base Path") ), wxVERTICAL );
	
	mBaseDirPicker = new wxDirPickerCtrl( this, wxID_ANY, wxT("Not configured"), wxT("Select OViSE's base folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_DIR_MUST_EXIST );
	BasePathSizer->Add( mBaseDirPicker, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	mMainSizer->Add( BasePathSizer, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* MediaPathSizer;
	MediaPathSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Media Path") ), wxVERTICAL );
	
	mMediaDirPicker = new wxDirPickerCtrl( this, wxID_ANY, wxT("Not configured"), wxT("Select OViSE's media folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_DIR_MUST_EXIST );
	MediaPathSizer->Add( mMediaDirPicker, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	mMainSizer->Add( MediaPathSizer, 0, wxEXPAND, 5 );
	
	this->SetSizer( mMainSizer );
	this->Layout();
	mMainSizer->Fit( this );
	
	this->Centre( wxBOTH );
}

PathConfigDialog::~PathConfigDialog()
{
}
