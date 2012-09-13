#!/bin/bash

date
DRUSH_PHP=/www/wdlinux/php/bin/php
export DRUSH_PHP
export PATH=$PATH:/home/robbin/bin/

drush cron
svn add sites/default/files/backup_migrate/scheduled/*
svn ci  sites/default/files/backup_migrate/scheduled/* -m 'add backup files'
date

drush cms --mode=formal


