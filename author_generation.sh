#!/usr/bin/env bash

set -e

SCRIPTDIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOTDIR="$(git -C "$SCRIPTDIR" rev-parse --show-toplevel)"

echo "ROOTDIR = $ROOTDIR"
echo "SCRIPTDIR = $SCRIPTDIR"

set -x

cat > "${ROOTDIR}/AUTHORS" <<- EOF
	$(git -C "$ROOTDIR" log --format='%aN <%aE>')
EOF
