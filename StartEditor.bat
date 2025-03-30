@echo off
CALL BuildProject.lua clean forcegen build
START %~dp0/"GameEngineProject.sln"
exit