// Konstruktor - An interactive LDraw modeler for KDE
// Copyright (c)2006-2011 Park "segfault" J. K. <mastermind@planetmono.org>

#ifndef _COMMANDBASE_H_
#define _COMMANDBASE_H_

#include <QSet>
#include <QUndoCommand>

namespace ldraw
{
    class model;
}

namespace Konstruktor
{

class CommandBase : public QUndoCommand
{
  public:
	enum AffectedRow { Inserted, Removed };
	typedef QPair<CommandBase::AffectedRow, QSet<int> > AffectedRowInfo;
	
	CommandBase(const QSet<int> &selection, ldraw::model *model);
	virtual ~CommandBase();

	virtual bool needUpdateDimension() const;
	virtual bool needRepaint() const;
	virtual AffectedRowInfo affectedRows() const;

	const QSet<int>& selection() const { return selection_; }
	ldraw::model* model() { return model_; }

  protected:
	QSet<int> selection_;
	ldraw::model *model_;
};

}

#endif
