#include "MyModel.h"
#include <QFont>
#include <QBrush>

GenesTableModel::GenesTableModel(Repo& r, QObject* parent) : QAbstractTableModel{ parent }, repo{ r }
{
}

GenesTableModel::~GenesTableModel()
{
}

int GenesTableModel::rowCount(const QModelIndex& parent) const
{
	//if (parent.isValid())	// for tree view
	//	return 0;
	int genesNumber = this->repo.get_repo_size();
	//return genesNumber;

	// Show a new empty row at the end, to allow adding data
	return genesNumber ;
}

int GenesTableModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant GenesTableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();

	// get the genes
	std::vector<TrenchCoat> genes = this->repo.get_vect_repo();

	// Allow adding in the table
	// this is to show an empty row at the end of the table - to allow adding new genes
	if (row == genes.size())
	{
		return QVariant();
	}

	// get the gene from the current row
	TrenchCoat g = genes[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(g.getSize());
		case 1:
			return QString::fromStdString(g.getColour());
		case 2:
			return QString::fromStdString(to_string(g.getPrice()));
		case 3:
			return QString::fromStdString(to_string(g.getQuantity()));
		case 4:
			return QString::fromStdString(g.getPhoto());
		default:
			break;
		}
	}
	if (role == Qt::FontRole)
	{
		QFont font("Times", 15, 10, true);
		font.setItalic(false);
		return font;
	}
	if (role == Qt::BackgroundRole)
	{
		if (row % 2 == 1)
		{
			return QBrush{ QColor{0, 250, 230} };
		}
	}

	return QVariant{};
}

QVariant GenesTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Size" };
			case 1:
				return QString{ "Colour" };
			case 2:
				return QString{ "Price" };
			case 3:
				return QString{ "Quantity" };
			case 4:
				return QString{ "Photograph" };
			default:
				break;
			}
		}
	}
	if (role == Qt::FontRole)
	{
		QFont font("Times", 15, 10, true);
		font.setBold(true);
		font.setItalic(false);
		return font;
	}

	return QVariant{};
}
