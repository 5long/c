#!/usr/bin/env ruby

def replay()
  home = ENV['HOME']
  exec "#{home}/.continuerc"
end

def record(cmd, *args)
  require 'shellwords'
  require 'fileutils'

  args = args.map {|arg| normalize arg}
  args.unshift cmd
  args.unshift 'exec'

  home = ENV['HOME']
  rcfile = "#{home}/.continuerc"
  File.open rcfile, 'w' do |f|
    f.puts '#!/bin/sh'
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
