#!/bin/bash

drush cron
svn add sites/default/files/backup_migrate/scheduled/*
svn ci  sites/default/files/backup_migrate/scheduled/* -m 'add backup files'

