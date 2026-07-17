#!/usr/bin/env bash

set -euo pipefail

# Run from the repository regardless of the caller's current directory.
cd -- "$(dirname -- "${BASH_SOURCE[0]}")"

# Make executables installed with `gem install --user-install` available.
if command -v ruby >/dev/null 2>&1; then
  user_gem_bin="$(ruby -e 'print File.join(Gem.user_dir, "bin")')"
  export PATH="${user_gem_bin}:${PATH}"
fi

if ! command -v bundle >/dev/null 2>&1; then
  echo "Bundler is not installed. Install it with:" >&2
  echo "  gem install --user-install bundler" >&2
  exit 1
fi

if ! bundle check >/dev/null 2>&1; then
  echo "Ruby dependencies are missing. Run 'bundle install' first." >&2
  exit 1
fi

echo "Starting the site at http://localhost:4000"
exec bundle exec jekyll serve --livereload "$@"
