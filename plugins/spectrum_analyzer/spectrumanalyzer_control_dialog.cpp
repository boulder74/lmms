/*
 * spectrumanaylzer_control_dialog.cpp - view for spectrum analyzer
 *
 * Copyright (c) 2008 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 * 
 * This file is part of Linux MultiMedia Studio - http://lmms.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


#include <QtGui/QLayout>
#include <QtGui/QPainter>

#include "spectrum_analyzer.h"
#include "song_editor.h"
#include "led_checkbox.h"
#include "embed.h"


inline void darken( QImage & _i, int _x, int _y, int _w, int _h )
{
	uchar * d = _i.scanLine( _y ) + _x * sizeof( QRgb );
	const int add = ( _i.width() - _w ) * sizeof( QRgb );
	for( int y = 0; y < _h; ++y )
	{
		for( int x = 0; x < _w; ++x )
		{
			*d = *d >> 1; ++d;
			*d = *d >> 1; ++d;
			*d = *d >> 1; ++d;
			++d;
		}
		d += add;
	}
}



class spectrumView : public QWidget
{
public:
	spectrumView( spectrumAnalyzer * _s, QWidget * _parent ) :
		QWidget( _parent ),
		m_sa( _s ),
		m_backgroundPlain( PLUGIN_NAME::getIconPixmap( "spectrum_background_plain" ).toImage() ),
		m_background( PLUGIN_NAME::getIconPixmap( "spectrum_background" ).toImage() )
	{
		setFixedSize( 249, 151 );
		connect( engine::getSongEditor(), SIGNAL( periodicUpdate() ),
				this, SLOT( update() ) );
		setAttribute( Qt::WA_OpaquePaintEvent, TRUE );
	}

	virtual ~spectrumView()
	{
	}

	virtual void paintEvent( QPaintEvent * _pe )
	{
		QPainter p( this );
		QImage i = m_sa->m_saControls.m_linearSpec.value() ?
					m_backgroundPlain : m_background;
		const double e = m_sa->m_energy;
		if( e <= 0 )
		{
			darken( i, 0, 0, i.width(), i.height() );
			p.drawImage( 0, 0, i );
			return;
		}

		const bool lin_y = m_sa->m_saControls.m_linearYAxis.value();
		double * b = m_sa->m_bands;
		const int LOWER_Y = -60;	// dB
		int h;
		if( m_sa->m_saControls.m_linearSpec.value() )
		{
			for( int x = 0; x < MAX_BANDS; ++x, ++b )
			{
				if( lin_y )
				{
					h = height() * (*b / e );
				}
				else
				{
					h = (int)( height() * (20*(log10( *b / e ) ) - LOWER_Y ) / (-LOWER_Y ) );
				}
				if( h < 0 )
				{
					h = 0;
				}
				else if( h > height() )
				{
					h = height();
				}
				darken( i, x, 0, 1, height()-h );
			}
		}
		else
		{
			for( int x = 0; x < 31; ++x, ++b )
			{
				if( lin_y )
				{
					h = height() * (*b / e );
				}
				else
				{
					h = (int)( height() * (20*(log10( *b / e ) ) - LOWER_Y ) / (-LOWER_Y ) );
				}
				if( h < 0 )
				{
					h = 0;
				}
				else if( h > height() )
				{
					h = height();
				}
				else
				{
					h = ( h / 3 ) * 3;
				}
				darken( i, x*8, 0, 8, height()-h );
			}
			darken( i, 31*8, 0, 1, height() );
		}
		p.drawImage( 0, 0, i );
	}

private:
	spectrumAnalyzer * m_sa;
	QImage m_backgroundPlain;
	QImage m_background;

} ;


spectrumAnalyzerControlDialog::spectrumAnalyzerControlDialog(
					spectrumAnalyzerControls * _controls ) :
	effectControlDialog( _controls )
{
	setAutoFillBackground( TRUE );
	QPalette pal;
	pal.setBrush( backgroundRole(),
				PLUGIN_NAME::getIconPixmap( "background" ) );
	setFixedSize( 280, 243 );
	setPalette( pal );
/*	QVBoxLayout * l = new QVBoxLayout( this );*/
	spectrumView * v = new spectrumView( _controls->m_effect, this );
	v->move( 24, 30 );

	ledCheckBox * lin_spec = new ledCheckBox( tr( "Linear spectrum" ), this );
	lin_spec->move( 24, 204 );
	lin_spec->setModel( &_controls->m_linearSpec );

	ledCheckBox * lin_y = new ledCheckBox( tr( "Linear Y axis" ), this );
	lin_y->move( 24, 220 );
	lin_y->setModel( &_controls->m_linearYAxis );
/*	l->addWidget( v );
	l->addWidget( lin_spec );
	l->addWidget( lin_y );*/

}

