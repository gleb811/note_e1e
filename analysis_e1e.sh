#!/bin/tcsh -f
rm analysis_e1e.pdf
rm analysis_e1e.aux
rm analysis_e1e.bbl
rm text/aliases/*.aux text/conclusions/*.aux text/event_selection/*.aux text/motivation/*.aux text/setups/*.aux text/title_page/*.aux text/toc/*.aux text/appendix/*.aux text/rad_corr/rad_corr.aux text/sys_err/*.aux text/bin_corr/*.aux text/cross_sction/*.aux
pdflatex analysis_e1e
bibtex analysis_e1e
pdflatex analysis_e1e
pdflatex analysis_e1e
acroread analysis_e1e.pdf >& /dev/null
rm analysis_e1e.log analysis_e1e.aux analysis_e1e.toc analysis_e1e.out analysis_e1e.blg analysis_e1e.bbl

