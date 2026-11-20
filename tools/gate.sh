#!/bin/sh
# Runs one merge gate with the pinned tools.
#
#     tools/gate.sh <toolcheck|scan|split|match|build> [args...]
#
# Steward calls this on the judge box (steward.toml). Run it yourself to check a unit the way the
# judge will.
#
# requirements.txt pins one commit of decompathon-xbox. .venv/.xbx-pin holds the sha256 of the
# requirements.txt that .venv was last installed from. When the two differ, the pinned tools are
# installed again before the gate runs, so a merged pin change reaches every workspace by itself.
set -eu

CDPATH= cd -- "$(dirname -- "$0")/.."

if command -v sha256sum >/dev/null 2>&1; then
    want=$(sha256sum requirements.txt | cut -d' ' -f1)
else
    want=$(shasum -a 256 requirements.txt | cut -d' ' -f1)
fi
have=$(cat .venv/.xbx-pin 2>/dev/null || true)

if [ "$want" != "$have" ] || [ ! -x .venv/bin/xbx ]; then
    if ! command -v uv >/dev/null 2>&1; then
        echo "tools/gate.sh: uv is not on PATH; it installs the pinned tools into .venv" >&2
        exit 127
    fi
    [ -x .venv/bin/python ] || uv venv .venv >&2
    uv pip install --python .venv/bin/python -r requirements.txt >&2
    printf '%s\n' "$want" > .venv/.xbx-pin
fi

exec .venv/bin/xbx gate "$@"
