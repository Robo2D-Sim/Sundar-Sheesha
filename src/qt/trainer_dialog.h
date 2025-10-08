// -*-c++-*-

/*!
  \file trainer_dialog.h
  \brief trainer dialog class Header File.
*/

/*
 *Copyright:

 Copyright (C) Hidehisa Akiyama

 This code is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3, or (at your option)
 any later version.

 This code is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this code; see the file COPYING.  If not, write to
 the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.

 *EndCopyright:
 */

/////////////////////////////////////////////////////////////////////

#ifndef SOCCERWINDOW2_QT_TRAINER_DIALOG_H
#define SOCCERWINDOW2_QT_TRAINER_DIALOG_H

#include <QDialog>

class QComboBox;
class QCheckBox;
class QLineEdit;
class QTimer;

class MainData;
class TrainerData;


//! field canvas configuration dialog
class TrainerDialog
    : public QDialog {

    Q_OBJECT

private:

    const MainData & M_main_data;
    TrainerData & M_trainer_data;

    QCheckBox * M_ball_cb;
    QLineEdit * M_ball_x;
    QLineEdit * M_ball_y;
    QCheckBox * M_ball_vel_cb;
    QLineEdit * M_ball_vx;
    QLineEdit * M_ball_vy;

    //QCheckBox * M_auto_repeat_cb;
    QLineEdit * M_auto_repeat_text;
    QTimer * M_auto_repeat_timer;

    QComboBox * M_playmode_cb;

    QCheckBox * M_left_all_cb;
    QCheckBox * M_left_cb[11];
    QLineEdit * M_left_x[11];
    QLineEdit * M_left_y[11];
    QLineEdit * M_left_body[11];

    QCheckBox * M_right_all_cb;
    QCheckBox * M_right_cb[11];
    QLineEdit * M_right_x[11];
    QLineEdit * M_right_y[11];
    QLineEdit * M_right_body[11];


public:

    TrainerDialog( QWidget * parent,
                   const MainData & main_data,
                   TrainerData & trainer_data );
    ~TrainerDialog();

protected:

    void closeEvent( QCloseEvent * e );

private:

    void createWidgets();

    QWidget * createBallBox();
    QWidget * createAutoRepeatBox();
    QWidget * createPlayModeBox();
    QWidget * createRecoverBox();
    QWidget * createLeftTeamBox();
    QWidget * createRightTeamBox();

private slots:

    void readFieldStatus();
    void open();
    void save();

    void toggleBallCheck( bool on );
    void toggleBallVelCheck( bool on );

    void toggleLeftAll( bool on );
    void toggleRightAll( bool on );

    void toggleLeftCheck( int index );
    void toggleRightCheck( int index );

    void changeAutoRepeatTimer( const QString & val );

    void sendCommand();

signals:

    void executed();

};

#endif
