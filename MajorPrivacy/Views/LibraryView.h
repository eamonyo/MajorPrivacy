#pragma once

#include "../../MiscHelpers/Common/PanelView.h"
#include "../../MiscHelpers/Common/TreeviewEx.h"
#include "../Models/LibraryModel.h"
#include "../Core/Programs/ProgramFile.h"
#include "../Core/Programs/ProgramLibrary.h"

class CLibraryView : public CPanelViewEx<CLibraryModel>
{
	Q_OBJECT

public:
	CLibraryView(QWidget *parent = 0);
	virtual ~CLibraryView();

	void					Sync(const QSet<CProgramFilePtr>& Programs, const QFlexGuid& EnclaveGuid = QString());

protected:
	virtual void			OnMenu(const QPoint& Point) override;
	//void					OnDoubleClicked(const QModelIndex& Index) override;

private slots:
	void					OnFileAction();
	//void					OnResetColumns();
	//void					OnColumnsChanged();
	void					OnCleanUpLibraries();
	void 					UpdateFilter() { m_FullRefresh = true; }

protected:

	QToolBar*				m_pToolBar;
	QComboBox*				m_pCmbGrouping;
	QComboBox*				m_pCmbSign;
	QComboBox*				m_pCmbAction;
	QToolButton*			m_pBtnCleanUp;
	QToolButton*			m_pBtnExpand;

	QAction*				m_pSignFile;
	QAction*				m_pRemoveSig;
	QAction*				m_pSignCert;
	QAction*				m_pRemoveCert;
	QAction*				m_pExplore;
	QAction*				m_pProperties;

	QSet<CProgramFilePtr>					m_CurPrograms;
	QFlexGuid								m_CurEnclaveGuid;
	QMap<SLibraryKey, SLibraryItemPtr>		m_ParentMap;
	QMap<SLibraryKey, SLibraryItemPtr>		m_LibraryMap;

	bool					m_FullRefresh = false;
};
