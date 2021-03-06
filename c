#!/usr/bin/env ruby

def rcfile
  home = ENV['HOME']
  "#{home}/.continuerc"
end

def replay()
  if File.exist?(rcfile)
    exec rcfile
  else
    STDERR.puts "No command recorded."
    exit 1
  end
end

def record(cmd, *args)
  require 'shellwords'
  require 'fileutils'

  args = args.map {|arg| normalize arg}
  args.unshift cmd
  args.unshift 'exec'

  File.open rcfile, 'w' do |f|
    f.puts '#!/bin/sh -e'
    f.puts args.shelljoin
  end
  FileUtils.chmod 'a+x', rcfile
end

def normalize(arg)
  File.exists?(arg) ? File.expand_path(arg)  : arg
end

def main
  action = ARGV.empty? ? :replay : :record
  send action, *ARGV
end

main if $PROGRAM_NAME == __FILE__
