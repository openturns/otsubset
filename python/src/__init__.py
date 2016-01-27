"""
    otsubset --- An OpenTURNS module
    ===================================================

    Contents
    --------
      'otsubset' is python module for OpenTURNS
      
"""

import sys
if sys.platform.startswith('win'):
    # this ensures OT dll is loaded
    import openturns
    
from .otsubset import *

__version__ = '1.2i'
